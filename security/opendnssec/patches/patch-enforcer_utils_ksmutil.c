$NetBSD: patch-enforcer_utils_ksmutil.c,v 1.1 2016/11/27 14:25:41 he Exp $

Avoid calling xmlCleanupThreads, xmlCleanupParser has called it
already, and this leads to an abort / assert failure with NetBSD
7.0 pthread.

--- enforcer/utils/ksmutil.c.orig	2016-10-17 12:32:58.000000000 +0000
+++ enforcer/utils/ksmutil.c
@@ -4440,7 +4440,6 @@ main (int argc, char *argv[])
 
     xmlCleanupParser();
     xmlCleanupGlobals();
-    xmlCleanupThreads();
 
     exit(result);
 }
