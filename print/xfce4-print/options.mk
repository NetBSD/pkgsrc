# $NetBSD: options.mk,v 1.1 2005/12/01 18:21:52 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-print
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-cups
.endif
