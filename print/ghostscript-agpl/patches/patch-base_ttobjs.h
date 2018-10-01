$NetBSD: patch-base_ttobjs.h,v 1.1 2018/10/01 09:21:32 jperkin Exp $

Avoid GS conflict on older SunOS.

--- base/ttobjs.h.orig	2018-09-13 10:02:01.000000000 +0000
+++ base/ttobjs.h
@@ -42,6 +42,10 @@
 #include "tttables.h"
 #include "setjmp_.h"
 
+#ifdef __sun
+#undef GS
+#endif
+
 #ifdef __cplusplus
   extern "C" {
 #endif
