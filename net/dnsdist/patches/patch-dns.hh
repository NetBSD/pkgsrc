$NetBSD: patch-dns.hh,v 1.1 2017/03/31 20:49:51 fhajny Exp $

Add NetBSD support.

--- dns.hh.orig	2016-12-29 12:45:46.000000000 +0000
+++ dns.hh
@@ -146,7 +146,7 @@ struct EDNS0Record
 
 static_assert(sizeof(EDNS0Record) == 4, "EDNS0Record size must be 4");
 
-#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #include <machine/endian.h>
 #elif __linux__ || __GNU__
 # include <endian.h>
