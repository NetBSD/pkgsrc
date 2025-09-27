$NetBSD: patch-skeylogin.c,v 1.1 2025/09/27 12:07:22 tnn Exp $

- add missing includes

--- skeylogin.c.orig	2025-09-27 11:55:09.734627011 +0000
+++ skeylogin.c
@@ -25,6 +25,7 @@
 #include <sys/types.h>
 
 #include <ctype.h>
+#include <err.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <stdio.h>
