$NetBSD: patch-zlibstubs.c,v 1.1 2016/05/05 11:27:47 jaapb Exp $

Use proper definition of zlib crc32 function
--- zlibstubs.c.orig	2012-10-12 03:36:07.000000000 +0000
+++ zlibstubs.c
@@ -168,7 +168,7 @@ value camlzip_inflateEnd(value vzs)
 
 value camlzip_update_crc32(value crc, value buf, value pos, value len)
 {
-  return caml_copy_int32(crc32((uint32) Int32_val(crc), 
+  return caml_copy_int32(crc32((uLong) Int32_val(crc), 
                           &Byte_u(buf, Long_val(pos)),
                           Long_val(len)));
 }
