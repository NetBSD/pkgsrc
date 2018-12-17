$NetBSD: patch-src_libspf2_spf__dns__resolv.c,v 1.1 2018/12/17 18:32:42 schmonz Exp $

OpenBSD's libc resolver provides res_init() but not res_close().

--- src/libspf2/spf_dns_resolv.c.orig	Sat Jan 28 08:24:47 2012
+++ src/libspf2/spf_dns_resolv.c
@@ -607,7 +607,9 @@ SPF_dns_resolv_free(SPF_dns_server_t *spf_dns_server)
 	SPF_ASSERT_NOTNULL(spf_dns_server);
 
 #if ! HAVE_DECL_RES_NINIT
+#  ifndef __OpenBSD__
 	res_close();
+#  endif
 #endif
 
 	free(spf_dns_server);
