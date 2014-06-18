# $NetBSD: options.mk,v 1.2 2014/06/18 09:26:10 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.epdfview
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups15/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cups
.else
CONFIGURE_ARGS+=	--without-cups
.endif
