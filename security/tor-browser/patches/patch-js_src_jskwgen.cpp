$NetBSD: patch-js_src_jskwgen.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- js/src/jskwgen.cpp.orig	2015-01-23 06:00:01.000000000 +0000
+++ js/src/jskwgen.cpp	2015-02-05 11:42:30.000000000 +0000
@@ -181,7 +181,7 @@
         *s++ = '\\';
         break;
       default:
-        if (!isprint(c)) {
+        if (!isprint(((unsigned char)c))) {
             *s++ = '\\';
             *s++ = (char)('0' + (0x3 & (((unsigned char)c) >> 6)));
             *s++ = (char)('0' + (0x7 & (((unsigned char)c) >> 3)));
