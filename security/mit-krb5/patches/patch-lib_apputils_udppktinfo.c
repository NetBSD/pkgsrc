$NetBSD: patch-lib_apputils_udppktinfo.c,v 1.1 2018/06/15 20:46:01 tez Exp $

Don't use IP_PKTINFO on NetBSD, it doesn't support all required fields.
(based on prior patch-lib_apputils_net-server.c)

--- ./lib/apputils/udppktinfo.c.orig	2018-06-13 17:53:37.880688500 +0000
+++ ./lib/apputils/udppktinfo.c
@@ -129,7 +129,7 @@ set_pktinfo(int sock, int family)
     }
 }
 
-#if defined(HAVE_PKTINFO_SUPPORT) && defined(CMSG_SPACE)
+#if defined(HAVE_PKTINFO_SUPPORT) && defined(CMSG_SPACE) && !defined(__NetBSD__)
 
 /*
  * Check if a socket is bound to a wildcard address.
