$NetBSD: patch-pdns_dns.hh,v 1.1 2012/05/20 19:37:49 marino Exp $

--- pdns/dns.hh.orig	2012-05-20 19:14:49.778625000 +0000
+++ pdns/dns.hh
@@ -173,7 +173,7 @@ enum  {
 #ifdef WIN32
 #define BYTE_ORDER 1
 #define LITTLE_ENDIAN 1
-#elif __FreeBSD__ || __APPLE__
+#elif defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__)
 #include <machine/endian.h>
 #elif __linux__
 # include <endian.h>
