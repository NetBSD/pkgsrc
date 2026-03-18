$NetBSD: patch-preproc.c,v 1.1 2026/03/18 10:08:44 nia Exp $

Include <alloca.h> on systems that need it, to avoid implicit
function declarations.

--- preproc.c.orig	2026-03-18 09:28:54.885993959 +0000
+++ preproc.c
@@ -27,6 +27,9 @@ preproc.c: Deskewing, balancing, thresho
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <math.h>
 #include "common.h"
 #include "gui.h"
