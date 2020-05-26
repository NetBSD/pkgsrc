$NetBSD: patch-lib_tsocket_tsocket__bsd.c,v 1.1 2020/05/26 13:11:01 jperkin Exp $

Avoid conflict with host s_addr.

--- lib/tsocket/tsocket_bsd.c.orig	2020-01-31 10:25:36.000000000 +0000
+++ lib/tsocket/tsocket_bsd.c
@@ -282,13 +282,13 @@ int _tsocket_address_bsd_from_sockaddr(T
 }
 
 int _tsocket_address_bsd_from_samba_sockaddr(TALLOC_CTX *mem_ctx,
-					 const struct samba_sockaddr *s_addr,
+					 const struct samba_sockaddr *samba_s_addr,
 					 struct tsocket_address **t_addr,
 					 const char *location)
 {
 	return _tsocket_address_bsd_from_sockaddr(mem_ctx,
-						  &s_addr->u.sa,
-						  s_addr->sa_socklen,
+						  &samba_s_addr->u.sa,
+						  samba_s_addr->sa_socklen,
 						  t_addr,
 						  location);
 }
