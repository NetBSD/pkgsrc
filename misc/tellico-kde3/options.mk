# $NetBSD: options.mk,v 1.2 2015/09/12 16:50:00 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tellico
PKG_SUPPORTED_OPTIONS=	poppler

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpoppler)
.include "../../print/poppler016-qt3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-poppler
.endif
