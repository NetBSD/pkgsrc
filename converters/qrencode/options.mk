# $NetBSD: options.mk,v 1.2 2019/11/03 17:14:26 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qrencode
PKG_SUPPORTED_OPTIONS=	static
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-static=yes
.else
CONFIGURE_ARGS+=	--enable-static=no
.endif
