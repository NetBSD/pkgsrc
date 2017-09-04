$NetBSD: patch-ifdata.c,v 1.1 2017/09/04 09:44:41 leot Exp $

Add NetBSD support.

--- ifdata.c.orig	2016-08-13 13:58:21.000000000 +0000
+++ ifdata.c
@@ -18,7 +18,7 @@
 	#include <net/if.h>
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
 	#define s6_addr16 __u6_addr.__u6_addr16
 	#include <net/if.h>
 #endif
