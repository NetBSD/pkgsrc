# $NetBSD: options.mk,v 1.1 2024/05/12 17:51:54 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.iortctw
PKG_SUPPORTED_OPTIONS=		openal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenal)
MAKE_FLAGS+=	USE_OPENAL=1
MAKE_FLAGS+=	USE_OPENAL_DLOPEN=0
.  include "../../audio/openal-soft/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_OPENAL=0
MAKE_FLAGS+=	USE_OPENAL_DLOPEN=0
.endif
