$NetBSD: patch-revision.c,v 1.1 2026/03/18 10:08:44 nia Exp $

Include <alloca.h> on systems that need it, to avoid implicit
function declarations.

--- revision.c.orig	2026-03-18 09:28:39.047057617 +0000
+++ revision.c
@@ -26,6 +26,9 @@ revision.c: Revision procedures
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include "common.h"
 #include "gui.h"
 
