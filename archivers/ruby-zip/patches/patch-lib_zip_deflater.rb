$NetBSD: patch-lib_zip_deflater.rb,v 1.1 2011/12/14 17:01:13 taca Exp $

o Use bytesize.

--- lib/zip/deflater.rb.orig	2011-12-13 22:22:33.000000000 +0000
+++ lib/zip/deflater.rb
@@ -11,7 +11,7 @@ module Zip
     def << (data)
       val = data.to_s
       @crc = Zlib::crc32(val, @crc)
-      @size += val.size
+      @size += val.bytesize
       @outputStream << @zlibDeflater.deflate(data)
     end
 
