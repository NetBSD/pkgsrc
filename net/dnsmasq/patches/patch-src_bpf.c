$NetBSD: patch-src_bpf.c,v 1.5 2015/05/06 06:08:48 mef Exp $

Add inet6 include for OS X

--- src/bpf.c.orig	2014-09-24 06:16:15.000000000 +0900
+++ src/bpf.c	2015-05-06 15:01:56.000000000 +0900
@@ -29,7 +29,7 @@
 #  include <net/if_var.h> 
 #endif
 #include <netinet/in_var.h>
-#ifdef HAVE_IPV6
+#if defined(HAVE_IPV6) || defined(__APPLE__)
 #  include <netinet6/in6_var.h>
 #endif
 
