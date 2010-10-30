# $NetBSD: options.mk,v 1.5 2010/10/30 15:07:42 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sox
PKG_SUPPORTED_OPTIONS=	lame oss
# lame has LICENSE= issues and thus should not be SUGGESTED.
PKG_SUGGESTED_OPTIONS=
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlame)
# This is an option due to LICENSE= issues.
.include "../../audio/lame/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-oss
.endif
