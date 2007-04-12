# $NetBSD: options.mk,v 1.3 2007/04/12 09:55:12 martti Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-print
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cups
.endif
