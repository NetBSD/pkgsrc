$NetBSD: patch-archive.c,v 1.1 2026/03/18 17:02:37 nia Exp $

Fix implicit decl of creat.

--- archive.c.orig	2026-03-18 16:46:13.934473532 +0000
+++ archive.c
@@ -12,6 +12,7 @@
 #endif
 
 #include <stdio.h>
+#include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <ctype.h>
