$NetBSD: patch-fdtest.c,v 1.1 2025/12/19 10:46:08 nia Exp $

Include <stdlib.h> for exit(3).

--- fdtest.c.orig	2025-12-19 10:35:53.526349178 +0000
+++ fdtest.c
@@ -11,6 +11,7 @@
  */
 
 #include	<stdio.h>
+#include	<stdlib.h>
 
 #include	"portlib.h"
 
