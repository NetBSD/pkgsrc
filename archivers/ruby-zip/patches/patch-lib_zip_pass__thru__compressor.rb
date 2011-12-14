$NetBSD: patch-lib_zip_pass__thru__compressor.rb,v 1.1 2011/12/14 17:01:13 taca Exp $

o Use bytesize.

--- lib/zip/pass_thru_compressor.rb.orig	2011-12-13 22:22:33.000000000 +0000
+++ lib/zip/pass_thru_compressor.rb
@@ -10,7 +10,7 @@ module Zip
     def << (data)
       val = data.to_s
       @crc = Zlib::crc32(val, @crc)
-      @size += val.size
+      @size += val.bytesize
       @outputStream << val
     end
 
