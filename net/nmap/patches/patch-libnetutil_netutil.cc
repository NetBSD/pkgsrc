$NetBSD: patch-libnetutil_netutil.cc,v 1.1 2014/06/07 23:12:16 rodent Exp $

OpenBSD's socket.h doesn't include <sys/uio.h>.

--- libnetutil/netutil.cc.orig	2013-07-28 22:08:48.000000000 +0000
+++ libnetutil/netutil.cc
@@ -147,6 +147,7 @@
 #if HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>  /* SIOCGIFCONF for Solaris */
 #endif
+#include <sys/uio.h>
 
 /* Define CMSG_* symbols for Solaris 9 and earlier. See
    http://wiki.opencsw.org/porting-faq#toc10. */
