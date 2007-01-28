# $NetBSD: options.mk,v 1.1 2007/01/28 00:13:49 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.epdfview
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cups
.else
CONFIGURE_ARGS+=	--without-cups
.endif
