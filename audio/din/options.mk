# $NetBSD: options.mk,v 1.1 2018/12/10 20:33:06 fox Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.din
PKG_OPTIONS_OPTIONAL_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	alsa jack
PKG_SUGGESTED_OPTIONS=		jack

.include "../../mk/bsd.options.mk"

###
### Support ALSA
###
.if !empty(PKG_OPTIONS:Malsa)
CXXFLAGS+=		-D__LINUX_ALSA__
LDFLAGS+=		-lasound
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

###
### Support JACK
###
.if !empty(PKG_OPTIONS:Mjack)
CXXFLAGS+=		-D__UNIX_JACK__
LDFLAGS+=		-ljack
.include "../../audio/jack/buildlink3.mk"
.endif
