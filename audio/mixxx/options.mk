# $NetBSD: options.mk,v 1.2 2019/10/06 13:45:42 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mixxx
PKG_SUPPORTED_OPTIONS=		wavpack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwavpack)
PLIST_SRCS+=	PLIST.wv
SCONS_ARGS+=	wv=1
.include "../../audio/wavpack/buildlink3.mk"
.else
SCONS_ARGS+=	wv=0
.endif
