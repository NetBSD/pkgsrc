$NetBSD: patch-tools_srs.c,v 1.1 2025/10/17 14:07:25 jperkin Exp $

Handle alloca.h.

--- tools/srs.c.orig	2025-10-17 14:05:44.800804173 +0000
+++ tools/srs.c
@@ -6,6 +6,9 @@
 # define HAVE_SYS_TIME_H
 # define HAVE_UNISTD_H
 #endif
+#ifdef HAVE_ALLOCA_H
+#include <alloca.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
