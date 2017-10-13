$NetBSD: patch-osport.h,v 1.1 2017/10/13 17:24:05 christos Exp $

NetBSD has in_pktinfo

--- osport.h.orig	2017-08-02 13:46:06.000000000 -0400
+++ osport.h	2017-10-13 12:48:43.585921159 -0400
@@ -35,7 +35,7 @@
 
 #endif /* defined(SOLARIS) */
 
-#if !defined(LINUX)
+#if !defined(LINUX) && !defined(NETBSD)
 
 /* Declare empty structure to make code portable and keep simple */
 struct in_pktinfo {
