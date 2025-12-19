$NetBSD: patch-atotest.c,v 1.1 2025/12/19 10:46:08 nia Exp $

Include <stdlib.h> for exit(3).

--- atotest.c.orig	2025-12-19 10:34:56.852020106 +0000
+++ atotest.c
@@ -14,6 +14,7 @@
  */
 
 #include	<stdio.h>
+#include	<stdlib.h>
 
 #include	"portlib.h"
 
