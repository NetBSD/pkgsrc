# $NetBSD: options.mk,v 1.1 2014/01/27 20:25:17 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dcraw
PKG_SUPPORTED_OPTIONS=	lcms
PKG_SUGGESTED_OPTIONS=	lcms

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlcms)
LIBS+=		-llcms2
.include "../../graphics/lcms2/buildlink3.mk"
.else
CFLAGS+=	-DNO_LCMS
.endif
