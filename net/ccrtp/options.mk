# $NetBSD: options.mk,v 1.2 2015/04/18 03:11:47 rodent Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ccrtp
PKG_OPTIONS_GROUP.tls=		libgcrypt openssl
PKG_OPTIONS_REQUIRED_GROUPS=	tls
PKG_SUGGESTED_OPTIONS+=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibgcrypt)
.include "../../security/libgcrypt/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.8
.include "../../security/openssl/buildlink3.mk"
.endif
