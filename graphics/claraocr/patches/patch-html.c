$NetBSD: patch-html.c,v 1.1 2026/03/18 10:08:44 nia Exp $

Include <alloca.h> on systems that need it, to avoid implicit
function declarations.

--- html.c.orig	2026-03-18 09:29:08.339313552 +0000
+++ html.c
@@ -25,6 +25,9 @@ html.c: HTML generation and parse
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdarg.h>
 #include "common.h"
 #include "gui.h"
