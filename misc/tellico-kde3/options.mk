# $NetBSD: options.mk,v 1.1.1.1 2010/02/15 14:52:46 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tellico
PKG_SUPPORTED_OPTIONS=	poppler

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpoppler)
.include "../../print/poppler-qt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-poppler
.endif
