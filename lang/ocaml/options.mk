# $NetBSD: options.mk,v 1.1 2017/09/08 09:12:44 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml
PKG_SUPPORTED_OPTIONS=	pic flambda spacetime
PKG_SUGGESTED_OPTIONS=	pic

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpic)
CONFIGURE_ARGS+=	-fPIC
.endif

.if !empty(PKG_OPTIONS:Mflambda)
CONFIGURE_ARGS+=	-flambda
.endif

.if !empty(PKG_OPTIONS:Mspacetime)
CONFIGURE_ARGS+=	-spacetime
.endif
