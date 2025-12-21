$NetBSD: patch-runt1asm.c,v 1.1 2025/12/21 13:57:33 prlw1 Exp $

Fix build: implicit declaration of function 'dup', 'exit', 'close'

--- runt1asm.c.orig	2000-11-15 19:30:57.000000000 +0000
+++ runt1asm.c
@@ -10,6 +10,8 @@
 #ifdef EXTERNAL_T1ASM
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
 #include <errno.h>
 
 FILE *ifp;
