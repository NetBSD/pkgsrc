$NetBSD: patch-misc_unzip.h,v 1.2 2018/03/07 12:34:55 wiz Exp $

Patch from upstream to improve build on NetBSD.

--- misc/unzip.h.orig	2016-03-03 14:12:07.000000000 +0000
+++ misc/unzip.h
@@ -49,6 +49,11 @@
 extern "C" {
 #endif
 
+// On NetBSD, OF is not defined in zconf.h, which is included by zlib.h.
+#ifndef OF
+#define OF(x) x
+#endif
+ 
 #ifndef _ZLIB_H
 #include "zlib.h"
 #endif
