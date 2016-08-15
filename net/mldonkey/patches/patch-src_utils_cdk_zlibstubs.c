$NetBSD: patch-src_utils_cdk_zlibstubs.c,v 1.1 2016/08/15 15:48:19 jaapb Exp $

Compile with OCaml 4.03
--- src/utils/cdk/zlibstubs.c.orig	2009-02-24 18:34:31.000000000 +0000
+++ src/utils/cdk/zlibstubs.c
@@ -191,7 +191,7 @@ value camlzip_inflateEnd(value vzs)
 
 value camlzip_update_crc32(value crc, value buf, value pos, value len)
 {
-  return copy_int32(crc32((uint32) Int32_val(crc), 
+  return copy_int32(crc32((uint32_t) Int32_val(crc), 
                           &Byte_u(buf, Long_val(pos)),
                           Long_val(len)));
 }
