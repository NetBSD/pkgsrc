$NetBSD: patch-lib_resolv.rb,v 1.3 2026/09/16 14:50:17 taca Exp $

Update resolv gem to 0.3.2.

--- lib/resolv.rb.orig	2026-07-16 04:03:30.000000000 +0000
+++ lib/resolv.rb
@@ -37,7 +37,7 @@ end
 
 class Resolv
 
-  VERSION = "0.3.1"
+  VERSION = "0.3.2"
 
   ##
   # Looks up the first IP address for +name+.
@@ -1219,6 +1219,13 @@ class Resolv
 
       class Str # :nodoc:
         def initialize(string)
+          # A label is limited to 63 octets. [RFC 1035 2.3.4] Checking it here
+          # makes it an invariant of the object: every label, however it was
+          # built, fits in its length octet and cannot wrap it. Callers turn
+          # this into the error their own contract promises.
+          if string.bytesize > 63
+            raise ArgumentError, "DNS label is too long (#{string.bytesize} bytes, max 63): #{string.inspect}"
+          end
           @string = string
           # case insensivity of DNS labels doesn't apply non-ASCII characters. [RFC 4343]
           # This assumes @string is given in ASCII compatible encoding.
@@ -1264,7 +1271,26 @@ class Resolv
         when Name
           return arg
         when String
-          return Name.new(Label.split(arg), /\.\z/ =~ arg ? true : false)
+          # A hostname is runtime data rather than a programming mistake, so
+          # both size limits surface as ResolvError to stay rescuable alongside
+          # the rest of name resolution. The type check below is a caller
+          # mistake and keeps raising ArgumentError.
+          begin
+            labels = Label.split(arg)
+          rescue ArgumentError => e
+            raise ResolvError.new(e.message)
+          end
+          # Label::Str enforces the per-label limit. Only the total is knowable
+          # here, and it counts the encoded form, so size starts at 1 for the
+          # root label's terminating zero octet. [RFC 1035 2.3.4, 3.1]
+          size = 1
+          labels.each do |label|
+            size += 1 + label.string.bytesize
+            if size > 255
+              raise ResolvError.new("DNS name is too long (#{size} octets, max 255): #{arg.inspect}")
+            end
+          end
+          return Name.new(labels, /\.\z/ =~ arg ? true : false)
         else
           raise ArgumentError.new("cannot interpret as DNS name: #{arg.inspect}")
         end
@@ -1386,12 +1412,24 @@ class Resolv
                @rd == other.rd &&
                @ra == other.ra &&
                @rcode == other.rcode &&
-               @question == other.question &&
+               question_equal?(other.question) &&
                @answer == other.answer &&
                @authority == other.authority &&
                @additional == other.additional
       end
 
+      # A question holds the resource class itself, and decoding creates a fresh
+      # class for each unknown type, so the classes cannot be compared by
+      # identity alone.
+      private def question_equal?(other_question) # :nodoc:
+        return false unless @question.length == other_question.length
+        @question.zip(other_question) {|(name, typeclass), (o_name, o_typeclass)|
+          return false unless name == o_name &&
+                              Resource::Generic.type_class_equal?(typeclass, o_typeclass)
+        }
+        return true
+      end
+
       def add_question(name, typeclass)
         @question << [Name.create(name), typeclass]
       end
@@ -1498,8 +1536,15 @@ class Resolv
         end
 
         def put_string(d)
-          self.put_pack("C", d.length)
-          @data << d
+          s = d.to_s
+          # A character-string is prefixed by a single length octet, so it can
+          # hold at most 255 octets. [RFC 1035 3.3] Reject anything longer to
+          # avoid silently truncating the length to its low 8 bits (mod 256).
+          if s.bytesize > 255
+            raise ArgumentError, "character-string is too long (#{s.bytesize} bytes, max 255): #{s.inspect}"
+          end
+          self.put_pack("C", s.bytesize)
+          @data << s
         end
 
         def put_string_list(ds)
@@ -1529,7 +1574,17 @@ class Resolv
         end
 
         def put_label(d)
-          self.put_string(d.to_s)
+          s = d.to_s
+          # Label::Str applies this limit when a label is built, so what is left
+          # for here is a raw string handed straight to put_labels. The two ways
+          # an over-long label goes wrong differ: 64 to 255 octets write a length
+          # octet in the reserved or compression pointer range, and 256 or more
+          # wrap it mod 256. Either way the encoded name stops being the name the
+          # caller asked for. [RFC 1035 2.3.4, 4.1.4]
+          if s.bytesize > 63
+            raise ArgumentError, "DNS label is too long (#{s.bytesize} bytes, max 63): #{s.inspect}"
+          end
+          self.put_string(s)
         end
       end
 
@@ -1655,7 +1710,9 @@ class Resolv
           prev_index = @index
           save_index = nil
           d = []
-          size = -1
+          # size counts the encoded form, so it starts at 1 for the root
+          # label's terminating zero octet. [RFC 1035 3.1]
+          size = 1
           while true
             raise DecodeError.new("limit exceeded") if @limit <= @index
             case @data.getbyte(@index)
@@ -1686,6 +1743,11 @@ class Resolv
 
         def get_label
           return Label::Str.new(self.get_string)
+        rescue ArgumentError => e
+          # A length octet of 64..191 is reserved rather than a label length,
+          # but this decoder used to read it as one. [RFC 1035 4.1.4] Report it
+          # the way the rest of a malformed message is reported.
+          raise DecodeError.new(e.message)
         end
 
         def get_question
@@ -1874,8 +1936,9 @@ class Resolv
           key_name = :"key#{key_number}"
           c.const_set(:KeyName, key_name)
           c.const_set(:KeyNumber, key_number)
-          self.const_set(:"Key#{key_number}", c)
-          ClassHash[key_name] = ClassHash[key_number] = c
+          # Not registered in a constant or in ClassHash. ClassHash creates a
+          # class for every unknown SvcParamKey, so registering them
+          # permanently would let a malicious response exhaust memory.
           return c
         end
       end
@@ -2173,12 +2236,28 @@ class Resolv
           return self.new(msg.get_bytes)
         end
 
+        # create makes a fresh class for each decoded resource, so the type and
+        # class values have to be compared instead of the class itself.
+        def self.type_class_equal?(klass, other) # :nodoc:
+          return true if klass.equal?(other)
+          Generic > klass && Generic > other &&
+            klass::TypeValue == other::TypeValue &&
+            klass::ClassValue == other::ClassValue
+        end
+
+        def ==(other) # :nodoc:
+          return other.is_a?(Generic) &&
+                 Generic.type_class_equal?(self.class, other.class) &&
+                 @data == other.data
+        end
+
         def self.create(type_value, class_value) # :nodoc:
           c = Class.new(Generic)
           c.const_set(:TypeValue, type_value)
           c.const_set(:ClassValue, class_value)
-          Generic.const_set("Type#{type_value}_Class#{class_value}", c)
-          ClassHash[[type_value, class_value]] = c
+          # Not registered in a constant or in ClassHash. get_class creates a
+          # class for every unknown (type, class) pair, so registering them
+          # permanently would let a malicious response exhaust memory.
           return c
         end
       end
