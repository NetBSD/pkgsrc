$NetBSD: patch-misc_unzip.h,v 1.1 2018/03/04 15:20:02 wiz Exp $

Define OF() macro that's not available everywhere.

--- misc/unzip.h.orig	2016-03-03 14:12:07.000000000 +0000
+++ misc/unzip.h
@@ -48,6 +48,9 @@
 #ifdef __cplusplus
 extern "C" {
 #endif
+#ifndef OF
+#define OF(x) x
+#endif
 
 #ifndef _ZLIB_H
 #include "zlib.h"
