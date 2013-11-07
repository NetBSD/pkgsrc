$NetBSD: patch-protocols_jabber_libiris_src_jdns_jdns_sys.c,v 1.1 2013/11/07 13:03:07 markd Exp $

--- protocols/jabber/libiris/src/jdns/jdns_sys.c.orig	2009-02-19 05:29:30.000000000 +1300
+++ protocols/jabber/libiris/src/jdns/jdns_sys.c
@@ -682,6 +682,9 @@ static jdns_dnsparams_t *dnsparams_get_u
 #if defined(__GLIBC__) && ((__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 3)))
 # define JDNS_MODERN_RES_API
 #endif
+#if defined(__RES) && (__RES >= 20030124)
+# define JDNS_MODERN_RES_API
+#endif
 
 #ifndef JDNS_MODERN_RES_API
 typedef int (*res_init_func)();
