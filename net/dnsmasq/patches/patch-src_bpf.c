$NetBSD: patch-src_bpf.c,v 1.3.2.1 2015/04/29 18:40:55 spz Exp $

Add inet6 include for OS X

--- src/bpf.c.orig     2015-01-02 04:23:05.000000000 +0000
+++ src/bpf.c
@@ -19,6 +19,10 @@
 #if defined(HAVE_BSD_NETWORK) || defined(HAVE_SOLARIS_NETWORK)
 #include <ifaddrs.h>
 
+#if defined(__APPLE__)
+#include <netinet6/in6_var.h>
+#endif
+
 #if defined(HAVE_BSD_NETWORK) && !defined(__APPLE__)
 #include <sys/param.h>
 #include <sys/sysctl.h>
