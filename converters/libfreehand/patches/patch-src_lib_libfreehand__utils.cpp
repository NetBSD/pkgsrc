$NetBSD: patch-src_lib_libfreehand__utils.cpp,v 1.1 2020/04/13 10:12:46 ryoon Exp $

* Fix build with textproc/icu-66.1.

--- src/lib/libfreehand_utils.cpp.orig	2017-09-16 10:28:50.000000000 +0000
+++ src/lib/libfreehand_utils.cpp
@@ -162,7 +162,7 @@ void libfreehand::_appendUTF16(libreveng
   while (j < length)
   {
     UChar32 c;
-    U16_NEXT(s, j, length, c)
+    U16_NEXT(s, j, length, c);
     unsigned char outbuf[U8_MAX_LENGTH+1];
     int i = 0;
     U8_APPEND_UNSAFE(&outbuf[0], i, c);
