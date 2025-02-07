$NetBSD: patch-build_rpmfc.c,v 1.3 2025/02/07 15:06:18 adam Exp $

sighandler_t is not portable.

--- build/rpmfc.c.orig	2024-10-07 09:35:46.000000000 +0000
+++ build/rpmfc.c
@@ -12,6 +12,11 @@
 #include <gelf.h>
 #endif
 
+#if !defined(__linux__)
+typedef void (*sighandler_t)(int);
+#include <libgen.h>
+#endif
+
 #include <rpm/header.h>
 #include <rpm/argv.h>
 #include <rpm/rpmfc.h>
