# $NetBSD: options.mk,v 1.1 2022/08/03 16:23:36 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sameboy
PKG_SUPPORTED_OPTIONS=		openal
PKG_SUGGESTED_OPTIONS.Darwin=	openal

.include "../../mk/bsd.options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKG_OPTIONS:Mopenal)
MAKE_FLAGS+=		ENABLE_OPENAL=1
.if ${OPSYS} != "Darwin"
.  include "../../audio/openal-soft/buildlink3.mk"
.endif
.else
MAKE_FLAGS+=		ENABLE_OPENAL=0
.endif
