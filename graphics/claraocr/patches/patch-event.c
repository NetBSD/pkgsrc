$NetBSD: patch-event.c,v 1.1 2026/03/18 10:08:44 nia Exp $

Include <alloca.h> on systems that need it, to avoid implicit
function declarations.

--- event.c.orig	2026-03-18 09:14:37.128605506 +0000
+++ event.c
@@ -22,6 +22,9 @@ event.c: GUI initialization and event ha
 
 */
 
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
