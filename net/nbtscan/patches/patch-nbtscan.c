$NetBSD: patch-nbtscan.c,v 1.1 2026/03/20 20:30:29 nia Exp $

Fix implicit decl of bzero(3).

--- nbtscan.c.orig	2026-03-20 20:17:41.280690533 +0000
+++ nbtscan.c
@@ -5,6 +5,7 @@
 #include <stdlib.h>
 #include <sys/time.h>
 #include <string.h>
+#include <strings.h>
 #if HAVE_STDINT_H
 #include <stdint.h>
 #endif
