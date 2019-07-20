# $NetBSD: options.mk,v 1.1 2019/07/20 10:39:18 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mixxx
PKG_SUPPORTED_OPTIONS=		wavpack

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	wavpack
.if !empty(PKG_OPTIONS:Mwavpack)
PLIST.wavpack=	yes
SCONS_ARGS+=	wv=1
.include "../../audio/wavpack/buildlink3.mk"
.else
SCONS_ARGS+=	wv=0
.endif
