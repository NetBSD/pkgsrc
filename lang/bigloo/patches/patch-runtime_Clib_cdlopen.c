$NetBSD: patch-runtime_Clib_cdlopen.c,v 1.1 2026/09/09 19:57:49 ktnb Exp $

Include required lib

--- runtime/Clib/cdlopen.c.orig	2026-02-19 08:14:24.000000000 +0000
+++ runtime/Clib/cdlopen.c
@@ -12,6 +12,9 @@
 #  include <windows.h>
 #endif
 #include <bigloo.h>
+#ifdef __NetBSD__
+#include <dlfcn.h>
+#endif
 
 /*---------------------------------------------------------------------*/
 /*    bgl_dlsym_custom_t                                               */
