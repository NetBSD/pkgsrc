# $NetBSD: options.mk,v 1.1 2017/07/04 13:50:41 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tcpflow
PKG_SUPPORTED_OPTIONS=	cairo

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcairo)
.include "../../graphics/cairo/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --enable-cairo=false
.endif
