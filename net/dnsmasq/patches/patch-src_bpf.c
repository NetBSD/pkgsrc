$NetBSD: patch-src_bpf.c,v 1.8 2017/03/21 09:18:15 fhajny Exp $

SunOS doesn't have netinet6/in6_var.h.

--- src/bpf.c.orig	2016-05-18 14:51:54.000000000 +0000
+++ src/bpf.c
@@ -31,7 +31,7 @@
 #  include <net/if_var.h> 
 #endif
 #include <netinet/in_var.h>
-#ifdef HAVE_IPV6
+#if defined(HAVE_IPV6) && defined(HAVE_BSD_NETWORK)
 #  include <netinet6/in6_var.h>
 #endif
 
