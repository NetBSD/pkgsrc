# $NetBSD: options.mk,v 1.4 2017/11/12 15:36:58 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.epdfview
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups-base/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cups
.else
CONFIGURE_ARGS+=	--without-cups
.endif
