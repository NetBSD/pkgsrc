# $NetBSD: options.mk,v 1.1 2009/11/25 10:13:06 kefren Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mono
PKG_SUPPORTED_OPTIONS=	moonlight
PKG_SUGGESTED_OPTIONS=	moonlight

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		moon

.if !empty(PKG_OPTIONS:Mmoonlight)
PLIST.moon=	yes
.else
CONFIGURE_ARGS+=	--with-moonlight=no
.endif
