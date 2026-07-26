$NetBSD: patch-source-lisp.c,v 1.1 2026/07/26 06:14:13 rillig Exp $

Add missing header to get proper declarations for exit and free.

--- source/lisp.c.orig	1999-06-23 15:15:16.000000000 +0000
+++ source/lisp.c
@@ -1,3 +1,4 @@
+#include <stdlib.h>
 #include "lisp.h"
 
 /*************************************************************************/
