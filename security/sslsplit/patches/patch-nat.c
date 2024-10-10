$NetBSD: patch-nat.c,v 1.1 2024/10/10 19:45:22 nia Exp $

Always include fcntl to avoid implicit declarations.

--- nat.c.orig	2024-10-10 19:38:06.412374175 +0000
+++ nat.c
@@ -35,6 +35,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
+#include <fcntl.h>
 
 #ifdef HAVE_PF
 #include <sys/types.h>
