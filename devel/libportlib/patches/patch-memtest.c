$NetBSD: patch-memtest.c,v 1.1 2025/12/19 10:46:08 nia Exp $

Include <stdlib.h> for exit(3).

--- memtest.c.orig	2025-12-19 10:35:33.882292679 +0000
+++ memtest.c
@@ -10,6 +10,7 @@
  */
 
 #include	<stdio.h>
+#include	<stdlib.h>
 
 #include	"portlib.h"
 
