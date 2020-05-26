$NetBSD: patch-lib_tsocket_tsocket.h,v 1.1 2020/05/26 13:11:01 jperkin Exp $

Avoid conflict with host s_addr.

--- lib/tsocket/tsocket.h.orig	2020-01-31 10:25:36.000000000 +0000
+++ lib/tsocket/tsocket.h
@@ -1000,12 +1000,12 @@ int tsocket_address_bsd_from_samba_socka
 					struct tsocket_address **t_addr);
 #else
 int _tsocket_address_bsd_from_samba_sockaddr(TALLOC_CTX *mem_ctx,
-					 const struct samba_sockaddr *s_addr,
+					 const struct samba_sockaddr *samba_s_addr,
 					 struct tsocket_address **t_addr,
 					 const char *location);
 
-#define tsocket_address_bsd_from_samba_sockaddr(mem_ctx, s_addr, t_addr) \
-	_tsocket_address_bsd_from_samba_sockaddr(mem_ctx, s_addr, t_addr, \
+#define tsocket_address_bsd_from_samba_sockaddr(mem_ctx, samba_s_addr, t_addr) \
+	_tsocket_address_bsd_from_samba_sockaddr(mem_ctx, samba_s_addr, t_addr, \
 						 __location__)
 #endif
 
