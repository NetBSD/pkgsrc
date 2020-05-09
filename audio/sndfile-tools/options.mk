# $NetBSD: options.mk,v 1.1 2020/05/09 09:55:32 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sndfile-tools
PKG_SUPPORTED_OPTIONS=	jack
PKG_SUGGESTED_OPTIONS=	jack

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=	yes
.  include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jack
.endif
