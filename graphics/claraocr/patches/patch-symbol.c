$NetBSD: patch-symbol.c,v 1.1 2026/03/18 10:08:44 nia Exp $

Include <alloca.h> on systems that need it, to avoid implicit
function declarations.

--- symbol.c.orig	2026-03-18 09:13:45.830269397 +0000
+++ symbol.c
@@ -26,6 +26,9 @@ symbol.c: Symbol stuff
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <math.h>
 #include "common.h"
 #include "gui.h"
