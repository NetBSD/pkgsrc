$NetBSD: patch-src_bpf.c,v 1.9 2020/04/29 12:38:52 adam Exp $

SunOS doesn't have netinet6/in6_var.h.

--- src/bpf.c.orig	2020-04-08 16:32:53.000000000 +0000
+++ src/bpf.c
@@ -31,7 +31,9 @@
 #  include <net/if_var.h> 
 #endif
 #include <netinet/in_var.h>
+#if defined(HAVE_BSD_NETWORK)
 #include <netinet6/in6_var.h>
+#endif
 
 #ifndef SA_SIZE
 #define SA_SIZE(sa)                                             \
