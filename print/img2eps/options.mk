# $NetBSD: options.mk,v 1.1 2005/07/14 14:52:08 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.img2eps
PKG_SUPPORTED_OPTIONS=	jasper
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjasper)
CONFIGURE_ARGS+=	--with-jpeg2000
.include "../../graphics/jasper/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-jpeg2000
.endif
