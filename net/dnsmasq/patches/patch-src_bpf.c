$NetBSD: patch-src_bpf.c,v 1.6 2015/07/14 09:57:13 fhajny Exp $

Add inet6 include for OS X
Fix build on SunOS

--- src/bpf.c.orig	2015-06-12 20:39:11.000000000 +0000
+++ src/bpf.c
@@ -20,7 +20,9 @@
 #include <ifaddrs.h>
 
 #include <sys/param.h>
+#if defined(HAVE_BSD_NETWORK)
 #include <sys/sysctl.h>
+#endif
 #include <net/if.h>
 #include <net/route.h>
 #include <net/if_dl.h>
@@ -29,7 +31,7 @@
 #  include <net/if_var.h> 
 #endif
 #include <netinet/in_var.h>
-#ifdef HAVE_IPV6
+#if (defined(HAVE_IPV6) && !defined(HAVE_SOLARIS_NETWORK)) || defined(__APPLE__)
 #  include <netinet6/in6_var.h>
 #endif
 
