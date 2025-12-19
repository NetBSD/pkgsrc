$NetBSD: patch-dirtest.c,v 1.1 2025/12/19 10:46:08 nia Exp $

Include <stdlib.h> for exit(3).

--- dirtest.c.orig	2025-12-19 10:35:59.560125667 +0000
+++ dirtest.c
@@ -11,6 +11,7 @@
  */
 
 #include	<stdio.h>
+#include	<stdlib.h>
 
 #include	"portlib.h"
 
