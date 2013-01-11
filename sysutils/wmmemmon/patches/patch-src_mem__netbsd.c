$NetBSD: patch-src_mem__netbsd.c,v 1.1 2013/01/11 00:07:41 joerg Exp $

--- src/mem_netbsd.c.orig	2013-01-10 22:01:30.000000000 +0000
+++ src/mem_netbsd.c
@@ -21,6 +21,7 @@
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/swap.h>
+#include <sys/vmmeter.h>
 
 /* initialize function */
 void
