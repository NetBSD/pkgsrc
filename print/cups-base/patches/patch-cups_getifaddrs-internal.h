$NetBSD: patch-cups_getifaddrs-internal.h,v 1.1 2020/05/26 08:36:56 triaxx Exp $

FreeBSD bug 182466 that still seems open:
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=182466

--- cups/getifaddrs-internal.h.orig	2020-04-27 18:04:29.000000000 +0000
+++ cups/getifaddrs-internal.h
@@ -39,6 +39,9 @@ typedef int socklen_t;
 
 #  ifndef _WIN32
 #    include <net/if.h>
+#    if defined(__FreeBSD__)
+#      include <netinet/in.h>
+#    endif /* __FreeBSD */
 #    include <resolv.h>
 #    ifdef HAVE_GETIFADDRS
 #      include <ifaddrs.h>
