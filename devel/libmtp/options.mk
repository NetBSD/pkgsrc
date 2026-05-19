# $NetBSD: options.mk,v 1.2 2026/05/19 13:32:22 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmtp
PKG_SUPPORTED_OPTIONS=	mtpz

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmtpz)
.include "../../security/libgcrypt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mtpz
.endif
