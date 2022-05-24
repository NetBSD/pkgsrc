# $NetBSD: options.mk,v 1.6 2022/05/24 18:25:38 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml
PKG_SUPPORTED_OPTIONS=	pic flambda
PKG_SUGGESTED_OPTIONS=	pic

.include "../../mk/bsd.prefs.mk"
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
