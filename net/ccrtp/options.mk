# $NetBSD: options.mk,v 1.3 2020/01/25 10:45:10 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ccrtp
PKG_OPTIONS_GROUP.tls=		libgcrypt openssl
PKG_OPTIONS_REQUIRED_GROUPS=	tls
PKG_SUGGESTED_OPTIONS+=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibgcrypt)
.include "../../security/libgcrypt/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif
