$NetBSD: patch-build.c,v 1.1 2026/03/18 10:08:44 nia Exp $

Include <alloca.h> on systems that need it, to avoid implicit
function declarations.

--- build.c.orig	2026-03-18 09:29:18.083314593 +0000
+++ build.c
@@ -25,6 +25,9 @@ build.c: The function build.
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <unistd.h>
 #include <math.h>
 #include "common.h"
