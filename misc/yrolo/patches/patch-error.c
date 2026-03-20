$NetBSD: patch-error.c,v 1.1 2026/03/20 09:28:45 nia Exp $

Fix implicit declaration of exit(3).

--- error.c.orig	2026-03-20 09:05:14.265830704 +0000
+++ error.c
@@ -36,6 +36,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #ifdef GccSucks
 #include <time.h>
