$NetBSD: patch-syncdir.c,v 1.1 2017/07/20 02:07:27 schmonz Exp $

Avoid a Linuxism.

--- syncdir.c.orig	1998-07-13 19:29:57.000000000 +0000
+++ syncdir.c
@@ -25,7 +25,7 @@
 #undef open
 #include <unistd.h>
 #include <string.h>
-#include <syscall.h>
+#include <sys/syscall.h>
 #include <stdio.h>
 #include <errno.h>
 
