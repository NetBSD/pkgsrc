$NetBSD: patch-lib_resolv.rb,v 1.1.2.2 2025/07/17 02:18:00 maya Exp $

Update resolv gem to 0.2.3.

--- lib/resolv.rb.orig	2025-03-26 04:18:02.000000000 +0000
+++ lib/resolv.rb
@@ -1624,6 +1624,7 @@ class Resolv
           prev_index = @index
           save_index = nil
           d = []
+          size = -1
           while true
             raise DecodeError.new("limit exceeded") if @limit <= @index
             case @data.getbyte(@index)
@@ -1644,7 +1645,10 @@ class Resolv
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
