# $NetBSD: options.mk,v 1.1 2022/04/06 16:32:21 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zam-plugins

.include "../../audio/jack/platform.mk"
.if ${PLATFORM_SUPPORTS_JACK:tl} == "yes"
PKG_SUPPORTED_OPTIONS+=		jack
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
