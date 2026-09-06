$NetBSD: patch-src_melt_io.c,v 1.1 2026/09/06 09:56:09 markd Exp $

NetBSD needs <sys/select.h>

--- src/melt/io.c.orig	2026-06-25 00:09:29.000000000 +0000
+++ src/melt/io.c
@@ -36,6 +36,9 @@
 #include <framework/mlt_types.h>
 #include <windows.h>
 #endif
+#ifdef __NetBSD__
+#include <sys/select.h>
+#endif
 
 /* Application header files */
 #include "io.h"
