$NetBSD: patch-src_libspf2_spf__dns__resolv.c,v 1.2 2018/12/17 19:24:44 schmonz Exp $

OpenBSD's libc resolver provides res_init() but not res_close().

--- src/libspf2/spf_dns_resolv.c.orig	2012-01-28 08:24:47.000000000 +0000
+++ src/libspf2/spf_dns_resolv.c
@@ -606,7 +606,7 @@ SPF_dns_resolv_free(SPF_dns_server_t *sp
 {
 	SPF_ASSERT_NOTNULL(spf_dns_server);
 
-#if ! HAVE_DECL_RES_NINIT
+#if HAVE_DECL_RES_CLOSE
 	res_close();
 #endif
 
