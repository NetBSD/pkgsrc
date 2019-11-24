# $NetBSD: options.mk,v 1.3 2019/11/24 09:23:13 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml
PKG_SUPPORTED_OPTIONS=	pic flambda spacetime
PKG_SUGGESTED_OPTIONS=	pic

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpic)
CONFIGURE_ARGS+=	--with-pic
.else
CONFIGURE_ARGS+=	--without-pic
.endif

.if !empty(PKG_OPTIONS:Mflambda)
CONFIGURE_ARGS+=	--enable-flambda
.else
CONFIGURE_ARGS+=	--disable-flambda
.endif

.if !empty(PKG_OPTIONS:Mspacetime)
CONFIGURE_ARGS+=	--enable-spacetime
.else
CONFIGURE_ARGS+=	--disable-spacetime
.endif
