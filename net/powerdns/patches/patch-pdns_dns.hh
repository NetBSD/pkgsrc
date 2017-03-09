$NetBSD: patch-pdns_dns.hh,v 1.5 2017/03/09 13:32:54 fhajny Exp $

Add NetBSD support.

--- pdns/dns.hh.orig	2017-01-17 08:43:49.000000000 +0000
+++ pdns/dns.hh
@@ -146,7 +146,7 @@ struct EDNS0Record
 
 static_assert(sizeof(EDNS0Record) == 4, "EDNS0Record size must be 4");
 
-#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #include <machine/endian.h>
 #elif __linux__ || __GNU__
 # include <endian.h>
