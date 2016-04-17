$NetBSD: patch-mozilla_js_src_jskwgen.cpp,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/js/src/jskwgen.cpp.orig	2016-04-07 21:33:24.000000000 +0000
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
