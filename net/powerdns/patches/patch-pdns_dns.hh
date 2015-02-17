$NetBSD: patch-pdns_dns.hh,v 1.3 2015/02/17 02:00:07 rodent Exp $

Add DragonFly support.
--- pdns/dns.hh.orig	2014-10-30 10:18:22.000000000 +0000
+++ pdns/dns.hh
@@ -207,7 +207,7 @@ enum  {
         ns_t_any = 255,         /* Wildcard match. */
 };
 
-#if __FreeBSD__ || __APPLE__ || __OpenBSD__ ||  defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #include <machine/endian.h>
 #elif __linux__ || __GNU__
 # include <endian.h>
