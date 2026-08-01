$NetBSD: patch-shell.c,v 1.1 2026/08/01 18:11:29 ryoon Exp $

--- shell.c.orig	2026-08-01 17:48:13.792234375 +0000
+++ shell.c
@@ -2,6 +2,7 @@
 
 #include<stdio.h>
 #include<stdlib.h>
+#include<string.h>
 #include<unistd.h>
 #include<errno.h>
 #include<setjmp.h>
