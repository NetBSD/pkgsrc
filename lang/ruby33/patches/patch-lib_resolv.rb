$NetBSD: patch-lib_resolv.rb,v 1.1.2.2 2025/07/17 02:32:56 maya Exp $

Update resolv gem to 0.3.1.

--- lib/resolv.rb.orig	2025-04-09 09:23:04.000000000 +0000
+++ lib/resolv.rb
@@ -37,7 +37,7 @@ end
 
 class Resolv
 
-  VERSION = "0.3.0"
+  VERSION = "0.3.1"
 
   ##
   # Looks up the first IP address for +name+.
@@ -1655,6 +1655,7 @@ class Resolv
           prev_index = @index
           save_index = nil
           d = []
+          size = -1
           while true
             raise DecodeError.new("limit exceeded") if @limit <= @index
             case @data.getbyte(@index)
@@ -1675,7 +1676,10 @@ class Resolv
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
