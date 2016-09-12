# $NetBSD: options.mk,v 1.4 2016/09/12 18:06:44 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freetype2
PKG_SUPPORTED_OPTIONS=	png

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--with-png=yes
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-png=no
.endif
