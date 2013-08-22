$NetBSD: patch-include_my__net.h,v 1.1 2013/08/22 11:09:46 christos Exp $

Only use gethostbyname_r if we have a declaration for it.

--- include/my_net.h.orig	2013-07-11 16:39:36.000000000 +0300
+++ include/my_net.h	2013-08-22 11:17:08.000000000 +0300
@@ -89,7 +89,7 @@
 #if !defined(HPUX10)
 struct hostent;
 #endif /* HPUX */
-#if !defined(HAVE_GETHOSTBYNAME_R)
+#if !defined(HAVE_GETHOSTBYNAME_R) || !HAVE_DECL_GETHOSTBYNAME_R
 struct hostent *my_gethostbyname_r(const char *name,
 				   struct hostent *result, char *buffer,
 				   int buflen, int *h_errnop);
