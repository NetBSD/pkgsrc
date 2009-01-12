# $NetBSD: options.mk,v 1.3 2009/01/12 21:12:40 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gqmpeg
PKG_OPTIONS_OPTIONAL_GROUPS=	recode
PKG_OPTIONS_GROUP.recode=	gqmpeg-japanese gqmpeg-russian

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgqmpeg-japanese)
CONFIGURE_ARGS+=	--enable-japanese
.endif

.if !empty(PKG_OPTIONS:Mgqmpeg-russian)
CONFIGURE_ARGS+=	--enable-russian
.endif
