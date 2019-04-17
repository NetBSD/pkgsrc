$NetBSD: patch-base_ttobjs.h,v 1.2 2019/04/17 08:28:44 adam Exp $

Avoid GS conflict on older SunOS.

--- base/ttobjs.h.orig	2019-04-04 07:43:14.000000000 +0000
+++ base/ttobjs.h
@@ -43,6 +43,10 @@
 #include "setjmp_.h"
 #include "ttfoutl.h"
 
+#ifdef __sun
+#undef GS
+#endif
+
 #ifdef __cplusplus
   extern "C" {
 #endif
