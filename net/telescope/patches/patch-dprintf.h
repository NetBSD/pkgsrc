$NetBSD: patch-dprintf.h,v 1.1 2025/09/08 09:52:02 vins Exp $

Solaris before 11.4 lacks dprintf().
Provide a local implementation.

--- dprintf.h.orig	2025-09-08 09:10:17.612928006 +0000
+++ dprintf.h
@@ -0,0 +1,3 @@
+#include <stdarg.h>
+
+extern int dprintf(int fd, const char *restrict format, ...);
