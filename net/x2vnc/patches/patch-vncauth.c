$NetBSD: patch-vncauth.c,v 1.1 2026/03/22 09:41:31 nia Exp $

Fix implicit declaration of dup(2).

--- vncauth.c.orig	2026-03-22 09:25:36.630005546 +0000
+++ vncauth.c
@@ -24,6 +24,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <vncauth.h>
