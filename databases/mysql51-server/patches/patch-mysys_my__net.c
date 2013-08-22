$NetBSD: patch-mysys_my__net.c,v 1.1 2013/08/22 11:09:46 christos Exp $

Only use gethostbyname_r if we have a declaration for it.

--- mysys/my_net.c.orig	2013-07-11 16:39:36.000000000 +0300
+++ mysys/my_net.c	2013-08-22 12:14:50.000000000 +0300
@@ -51,7 +51,7 @@
   usage of getbostbyname_r simpler.
 */
 
-#if defined(HAVE_GETHOSTBYNAME_R)
+#if defined(HAVE_GETHOSTBYNAME_R) && HAVE_DECL_GETHOSTBYNAME_R
 
 #if defined(HAVE_GETHOSTBYNAME_R_GLIBC2_STYLE)
 
