$NetBSD: patch-AIO.xs,v 1.1 2015/03/17 10:37:14 jperkin Exp $

Avoid PAGESIZE macro on SunOS.

--- AIO.xs.orig	2014-11-21 14:49:56.000000000 +0000
+++ AIO.xs
@@ -159,9 +159,11 @@ static void req_destroy  (eio_req *grp);
 # define minor(dev) ((dev) & 0xff)
 #endif
 
+#ifndef __sun
 #if PAGESIZE <= 0
 # define PAGESIZE sysconf (_SC_PAGESIZE)
 #endif
+#endif
 
 /*****************************************************************************/
 
