$NetBSD: patch-src_network.c,v 1.1 2026/03/21 10:38:34 nia Exp $

Fix implicit function declarations.

--- src/network.c.orig	2026-03-21 10:18:36.685564505 +0000
+++ src/network.c
@@ -11,6 +11,7 @@
 /* System includes */
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <sys/types.h>
 #ifdef PLATFORM_WINNT
   #include <windows.h>
