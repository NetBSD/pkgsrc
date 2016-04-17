$NetBSD: patch-mozilla_js_src_jskwgen.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/js/src/jskwgen.cpp.orig	2015-06-08 17:49:25.000000000 +0000
+++ mozilla/js/src/jskwgen.cpp
@@ -181,7 +181,7 @@ qchar(char c, char* quoted_buffer)
         *s++ = '\\';
         break;
       default:
-        if (!isprint(c)) {
+        if (!isprint(((unsigned char)c))) {
             *s++ = '\\';
             *s++ = (char)('0' + (0x3 & (((unsigned char)c) >> 6)));
             *s++ = (char)('0' + (0x7 & (((unsigned char)c) >> 3)));
