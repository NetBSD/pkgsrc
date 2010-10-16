# $NetBSD: options.mk,v 1.3 2010/10/16 04:32:18 kefren Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mono
PKG_SUPPORTED_OPTIONS=	moonlight
# PKG_SUGGESTED_OPTIONS=	moonlight

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		moon

.if !empty(PKG_OPTIONS:Mmoonlight)
PLIST.moon=	yes
CONFIGURE_ARGS+=	--with-moonlight=yes
.else
CONFIGURE_ARGS+=	--with-moonlight=no
.endif
