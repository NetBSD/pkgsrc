# $NetBSD: options.mk,v 1.1 2019/07/16 15:45:03 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libraw
PKG_SUPPORTED_OPTIONS=		jasper

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjasper)
CONFIGURE_ARGS+=	--enable-jasper
# jasper uses SIZE_MAX and friends in its headers.
CPPFLAGS+=		-D__STDC_LIMIT_MACROS
.include "../../graphics/jasper/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jasper
.endif
