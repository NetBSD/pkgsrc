# $NetBSD: options.mk,v 1.1 2016/04/09 10:09:14 richard Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmtp
PKG_SUPPORTED_OPTIONS=	mtpz
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmtpz)
.include "../../security/libgcrypt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mtpz
.endif
