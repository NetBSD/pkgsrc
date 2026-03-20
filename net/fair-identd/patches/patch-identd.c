$NetBSD: patch-identd.c,v 1.1 2026/03/20 09:59:59 nia Exp $

Fix implicit declaration of exit(3).

--- identd.c.orig	2026-03-20 09:37:28.937868067 +0000
+++ identd.c
@@ -28,6 +28,7 @@
 #include <unistd.h>
 #include <string.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 #define	STDIN	0
 #define	STDOUT	1
