$NetBSD: patch-speed.c,v 1.1 2026/03/17 08:13:32 nia Exp $

Fix implicit declaration of exit.

--- speed.c.orig	2026-03-17 07:44:26.477000986 +0000
+++ speed.c
@@ -64,6 +64,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #ifndef MSDOS
 #include <unistd.h>
 #else
