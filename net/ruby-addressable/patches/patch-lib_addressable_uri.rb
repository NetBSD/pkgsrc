$NetBSD: patch-lib_addressable_uri.rb,v 1.1 2011/11/06 07:44:28 obache Exp $

* some fixes and improvements (from upstream repo).

--- lib/addressable/uri.rb.orig	2011-11-06 07:18:52.000000000 +0000
+++ lib/addressable/uri.rb
@@ -325,7 +325,11 @@ module Addressable
       return nil if component.nil?
 
       begin
-        component = component.to_str
+        if component.kind_of?(Symbol) || component.kind_of?(Numeric)
+          component = component.to_s
+        else
+          component = component.to_str
+        end
       rescue TypeError, NoMethodError
         raise TypeError, "Can't convert #{component.class} into String."
       end if !component.is_a? String
@@ -715,6 +719,7 @@ module Addressable
         self.authority = options[:authority] if options[:authority]
         self.path = options[:path] if options[:path]
         self.query = options[:query] if options[:query]
+        self.query_values = options[:query_values] if options[:query_values]
         self.fragment = options[:fragment] if options[:fragment]
       end
     end
@@ -1497,39 +1502,55 @@ module Addressable
         # Only to be used for non-Array inputs. Arrays should preserve order.
         new_query_values.sort!
       end
-      # new_query_values have form [['key1', 'value1'], ['key2', 'value2']]
 
-      # Algorithm shamelessly stolen from Julien Genestoux, slightly modified
-      buffer = ""
-      stack = []
-      e = lambda do |component|
-        component = component.to_s if component.kind_of?(Symbol)
-        URI.encode_component(component, CharacterClasses::UNRESERVED)
-      end
-      new_query_values.each do |key, value|
-        if value.kind_of?(Hash)
-          stack << [key, value]
-        elsif value.kind_of?(Array)
-          stack << [
-            key,
-            value.inject({}) { |accu, x| accu[accu.size.to_s] = x; accu }
-          ]
+      ##
+      # Joins and converts parent and value into a properly encoded and
+      # ordered URL query.
+      #
+      # @private
+      # @param [String] parent an URI encoded component.
+      # @param [Array, Hash, Symbol, #to_str] value
+      #
+      # @return [String] a properly escaped and ordered URL query.
+      to_query = lambda do |parent, value|
+        if value.is_a?(Hash)
+          value = value.map do |key, val|
+            [
+              URI.encode_component(key, CharacterClasses::UNRESERVED),
+              val
+            ]
+          end
+          value.sort!
+          buffer = ""
+          value.each do |key, val|
+            new_parent = "#{parent}[#{key}]"
+            buffer << "#{to_query.call(new_parent, val)}&"
+          end
+          return buffer.chop
+        elsif value.is_a?(Array)
+          buffer = ""
+          value.each_with_index do |val, i|
+            new_parent = "#{parent}[#{i}]"
+            buffer << "#{to_query.call(new_parent, val)}&"
+          end
+          return buffer.chop
         elsif value == true
-          buffer << "#{e.call(key)}&"
+          return parent
         else
-          buffer << "#{e.call(key)}=#{e.call(value)}&"
+          encoded_value = URI.encode_component(
+            value, CharacterClasses::UNRESERVED
+          )
+          return "#{parent}=#{encoded_value}"
         end
       end
-      stack.each do |(parent, hash)|
-        (hash.sort_by { |key| key.to_s }).each do |(key, value)|
-          if value.kind_of?(Hash)
-            stack << ["#{parent}[#{key}]", value]
-          elsif value == true
-            buffer << "#{parent}[#{e.call(key)}]&"
-          else
-            buffer << "#{parent}[#{e.call(key)}]=#{e.call(value)}&"
-          end
-        end
+
+      # new_query_values have form [['key1', 'value1'], ['key2', 'value2']]
+      buffer = ""
+      new_query_values.each do |parent, value|
+        encoded_parent = URI.encode_component(
+          parent, CharacterClasses::UNRESERVED
+        )
+        buffer << "#{to_query.call(encoded_parent, value)}&"
       end
       self.query = buffer.chop
     end
@@ -2182,7 +2203,7 @@ module Addressable
         parent = normalized_path.match(NPATH2)
         if parent && ((parent[1] != PARENT1 && parent[1] != PARENT2) \
                       || (parent[2] != PARENT1 && parent[2] != PARENT2))
-          mod ||= normalized_path.gsub!(/\/#{parent[1]}\/\.\.\/|(\/#{parent[2]}\/\.\.$)/, SLASH)
+          mod ||= normalized_path.gsub!(/\/#{Regexp.escape(parent[1].to_s)}\/\.\.\/|(\/#{Regexp.escape(parent[2].to_s)}\/\.\.$)/, SLASH)
         end
 
         mod ||= normalized_path.gsub!(NPATH3, EMPTYSTR)
