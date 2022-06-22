# $NetBSD: options.mk,v 1.2 2022/06/22 10:12:02 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zam-plugins

PKG_SUPPORTED_OPTIONS+=		jack

.include "../../audio/jack/platform.mk"
.if ${PLATFORM_SUPPORTS_JACK:tl} == "yes"
PKG_SUGGESTED_OPTIONS+=		jack
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=	yes
MAKE_FLAGS+=	HAVE_JACK=true
.  include "../../audio/jack/buildlink3.mk"
.else
MAKE_FLAGS+=	HAVE_JACK=false
.endif
