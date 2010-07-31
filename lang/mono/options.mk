# $NetBSD: options.mk,v 1.2 2010/07/31 08:40:37 kefren Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mono
PKG_SUPPORTED_OPTIONS=	moonlight
# PKG_SUGGESTED_OPTIONS=	moonlight

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		moon

.if !empty(PKG_OPTIONS:Mmoonlight)
PLIST.moon=	yes
CONFIGURE_ARGS+=	--with-mcs-docs=yes
.else
CONFIGURE_ARGS+=	--with-moonlight=no
.endif
