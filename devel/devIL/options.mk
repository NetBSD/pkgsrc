# $NetBSD: options.mk,v 1.1 2019/07/16 22:45:42 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.devIL
PKG_SUPPORTED_OPTIONS=	jasper

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjasper)
CONFIGURE_ARGS+=	--enable-jp2
.include "../../graphics/jasper/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jp2
.endif
