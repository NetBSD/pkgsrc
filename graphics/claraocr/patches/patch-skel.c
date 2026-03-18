$NetBSD: patch-skel.c,v 1.1 2026/03/18 10:08:44 nia Exp $

Include <alloca.h> on systems that need it, to avoid implicit
function declarations.

--- skel.c.orig	2026-03-18 09:14:43.575913764 +0000
+++ skel.c
@@ -22,6 +22,9 @@ skel.c: Skeleton computation
 
 */
 
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
