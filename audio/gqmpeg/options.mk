# $NetBSD: options.mk,v 1.1 2005/05/31 12:20:11 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gqmpeg
PKG_SUPPORTED_OPTIONS=	gqmpeg-japanese gqmpeg-russian
PKG_SUGGESTED_OPTIONS=	gqmpeg-japanese gqmpeg-russian
PKG_OPTIONS_LEGACY_VARS+= GQMPEG_NO_JAPANESE:-gqmpeg-japanese GQMPEG_NO_RUSSIAN:-gqmpeg-russian

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgqmpeg-japanese)
CONFIGURE_ARGS+=	--enable-japanese
.endif

.if !empty(PKG_OPTIONS:Mgqmpeg-russian)
CONFIGURE_ARGS+=	--enable-russian
.endif
