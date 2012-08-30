$NetBSD: patch-src-rxkad-fcrypt.c,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/rxkad/fcrypt.c.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/rxkad/fcrypt.c	2012-05-02 14:45:51.000000000 -0400
@@ -16,7 +16,6 @@
 #include <afs/param.h>
 #include <afs/stds.h>
 
-#define DEBUG 0
 #ifdef KERNEL
 #ifndef UKERNEL
 #if defined(AFS_AIX_ENV) || defined(AFS_AUX_ENV) || defined(AFS_SUN5_ENV)
