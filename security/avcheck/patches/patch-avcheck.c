$NetBSD: patch-avcheck.c,v 1.1 2026/03/17 08:12:43 nia Exp $

Fix implicit declaration of alloca.

--- avcheck.c.orig	2026-03-17 07:48:23.906221705 +0000
+++ avcheck.c
@@ -4,6 +4,9 @@
  * Public domain.
  */
 
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
