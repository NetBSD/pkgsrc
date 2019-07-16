# $NetBSD: options.mk,v 1.2 2019/07/16 22:50:24 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dcraw
PKG_SUPPORTED_OPTIONS=	lcms jasper
PKG_SUGGESTED_OPTIONS=	lcms

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlcms)
LIBS+=		-llcms2
.include "../../graphics/lcms2/buildlink3.mk"
.else
CPPFLAGS+=	-DNO_LCMS
.endif

.if !empty(PKG_OPTIONS:Mjasper)
LIBS+=		-ljasper
.include "../../graphics/jasper/buildlink3.mk"
.else
CPPFLAGS+=	-DNO_JASPER
.endif
