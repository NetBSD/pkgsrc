# $NetBSD: options.mk,v 1.5 2022/04/12 23:38:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freetype2
PKG_SUPPORTED_OPTIONS=	png
PKG_SUGGESTED_OPTIONS=	png

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--with-png=yes
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-png=no
.endif
