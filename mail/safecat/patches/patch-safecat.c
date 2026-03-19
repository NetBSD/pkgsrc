$NetBSD: patch-safecat.c,v 1.1 2026/03/19 07:50:46 nia Exp $

Fix implicit function declarations.

--- safecat.c.orig	2026-03-19 07:32:32.937755930 +0000
+++ safecat.c
@@ -24,6 +24,7 @@
 #include <fcntl.h>
 #include <signal.h>
 #include <unistd.h>
+#include <stdlib.h>
 
 /* Support for large files (on Linux systems, if the appropriate
    compile-time flag is used. */
