$NetBSD: patch-git-compat-util.h,v 1.1 2014/01/01 16:05:51 bsiegert Exp $

MirBSD does not define u_short and u_long when _XOPEN_SOURCE is defined.

--- git-compat-util.h.orig	Tue Dec  3 19:34:59 2013
+++ git-compat-util.h
@@ -75,7 +75,7 @@
 # endif
 #elif !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__USLC__) && \
       !defined(_M_UNIX) && !defined(__sgi) && !defined(__DragonFly__) && \
-      !defined(__TANDEM) && !defined(__QNX__)
+      !defined(__TANDEM) && !defined(__QNX__) && !defined(__MirBSD__)
 #define _XOPEN_SOURCE 600 /* glibc2 and AIX 5.3L need 500, OpenBSD needs 600 for S_ISLNK() */
 #define _XOPEN_SOURCE_EXTENDED 1 /* AIX 5.3L needs this */
 #endif
