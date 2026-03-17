$NetBSD: patch-rule.c,v 1.1 2026/03/17 08:11:14 nia Exp $

Fix implicit declaration of bzero(3).

--- rule.c.orig	2026-03-17 07:52:12.529244336 +0000
+++ rule.c
@@ -28,6 +28,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <unistd.h>
 #include <signal.h>
 #include <sys/wait.h>
