$NetBSD: patch-lib_resolv.rb,v 1.1.2.2 2025/07/17 02:45:43 maya Exp $

Update resolv gem to 0.6.2.

--- lib/resolv.rb.orig	2025-05-14 03:11:06.000000000 +0000
+++ lib/resolv.rb
@@ -33,7 +33,7 @@ require 'securerandom'
 
 class Resolv
 
-  VERSION = "0.6.0"
+  VERSION = "0.6.2"
 
   ##
   # Looks up the first IP address for +name+.
@@ -173,13 +173,16 @@ class Resolv
 
   class ResolvTimeout < Timeout::Error; end
 
+  WINDOWS = /mswin|cygwin|mingw|bccwin/ =~ RUBY_PLATFORM || ::RbConfig::CONFIG['host_os'] =~ /mswin/
+  private_constant :WINDOWS
+
   ##
   # Resolv::Hosts is a hostname resolver that uses the system hosts file.
 
   class Hosts
-    if /mswin|mingw|cygwin/ =~ RUBY_PLATFORM and
+    if WINDOWS
       begin
-        require 'win32/resolv'
+        require 'win32/resolv' unless defined?(Win32::Resolv)
         DefaultFileName = Win32::Resolv.get_hosts_path || IO::NULL
       rescue LoadError
       end
@@ -659,8 +662,20 @@ class Resolv
       }
     end
 
-    def self.bind_random_port(udpsock, bind_host="0.0.0.0") # :nodoc:
-      begin
+    case RUBY_PLATFORM
+    when *[
+      # https://www.rfc-editor.org/rfc/rfc6056.txt
+      # Appendix A. Survey of the Algorithms in Use by Some Popular Implementations
+      /freebsd/, /linux/, /netbsd/, /openbsd/, /solaris/,
+      /darwin/, # the same as FreeBSD
+    ] then
+      def self.bind_random_port(udpsock, bind_host="0.0.0.0") # :nodoc:
+        udpsock.bind(bind_host, 0)
+      end
+    else
+      # Sequential port assignment
+      def self.bind_random_port(udpsock, bind_host="0.0.0.0") # :nodoc:
+        # Ephemeral port number range recommended by RFC 6056
         port = random(1024..65535)
         udpsock.bind(bind_host, port)
       rescue Errno::EADDRINUSE, # POSIX
@@ -983,13 +998,13 @@ class Resolv
             next unless keyword
             case keyword
             when 'nameserver'
-              nameserver.concat(args)
+              nameserver.concat(args.each(&:freeze))
             when 'domain'
               next if args.empty?
-              search = [args[0]]
+              search = [args[0].freeze]
             when 'search'
               next if args.empty?
-              search = args
+              search = args.each(&:freeze)
             when 'options'
               args.each {|arg|
                 case arg
@@ -1000,22 +1015,22 @@ class Resolv
             end
           }
         }
-        return { :nameserver => nameserver, :search => search, :ndots => ndots }
+        return { :nameserver => nameserver.freeze, :search => search.freeze, :ndots => ndots.freeze }.freeze
       end
 
       def Config.default_config_hash(filename="/etc/resolv.conf")
         if File.exist? filename
-          config_hash = Config.parse_resolv_conf(filename)
+          Config.parse_resolv_conf(filename)
+        elsif WINDOWS
+          require 'win32/resolv' unless defined?(Win32::Resolv)
+          search, nameserver = Win32::Resolv.get_resolv_info
+          config_hash = {}
+          config_hash[:nameserver] = nameserver if nameserver
+          config_hash[:search] = [search].flatten if search
+          config_hash
         else
-          if /mswin|cygwin|mingw|bccwin/ =~ RUBY_PLATFORM
-            require 'win32/resolv'
-            search, nameserver = Win32::Resolv.get_resolv_info
-            config_hash = {}
-            config_hash[:nameserver] = nameserver if nameserver
-            config_hash[:search] = [search].flatten if search
-          end
+          {}
         end
-        config_hash || {}
       end
 
       def lazy_initialize
@@ -1664,6 +1679,7 @@ class Resolv
           prev_index = @index
           save_index = nil
           d = []
+          size = -1
           while true
             raise DecodeError.new("limit exceeded") if @limit <= @index
             case @data.getbyte(@index)
@@ -1684,7 +1700,10 @@ class Resolv
               end
               @index = idx
             else
-              d << self.get_label
+              l = self.get_label
+              d << l
+              size += 1 + l.string.bytesize
+              raise DecodeError.new("name label data exceed 255 octets") if size > 255
             end
           end
         end
@@ -2110,7 +2129,14 @@ class Resolv
 
       attr_reader :ttl
 
-      ClassHash = {} # :nodoc:
+      ClassHash = Module.new do
+        module_function
+
+        def []=(type_class_value, klass)
+          type_value, class_value = type_class_value
+          Resource.const_set(:"Type#{type_value}_Class#{class_value}", klass)
+        end
+      end
 
       def encode_rdata(msg) # :nodoc:
         raise NotImplementedError.new
@@ -2148,7 +2174,9 @@ class Resolv
       end
 
       def self.get_class(type_value, class_value) # :nodoc:
-        return ClassHash[[type_value, class_value]] ||
+        cache = :"Type#{type_value}_Class#{class_value}"
+
+        return (const_defined?(cache) && const_get(cache)) ||
                Generic.create(type_value, class_value)
       end
 
@@ -2577,7 +2605,7 @@ class Resolv
         end
 
         ##
-        # Flags for this proprty:
+        # Flags for this property:
         # - Bit 0 : 0 = not critical, 1 = critical
 
         attr_reader :flags
