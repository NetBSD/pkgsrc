$NetBSD: patch-pdns_dns.hh,v 1.2 2014/12/10 14:50:09 fhajny Exp $

Add DragonFly support.
--- pdns/dns.hh.orig	2014-10-30 10:18:22.000000000 +0000
+++ pdns/dns.hh
@@ -207,7 +207,7 @@ enum  {
         ns_t_any = 255,         /* Wildcard match. */
 };
 
-#if __FreeBSD__ || __APPLE__ || __OpenBSD__ ||  defined(__FreeBSD_kernel__)
+#if __FreeBSD__ || __APPLE__ || __OpenBSD__ || __DragonFly__ || defined(__FreeBSD_kernel__)
 #include <machine/endian.h>
 #elif __linux__ || __GNU__
 # include <endian.h>
