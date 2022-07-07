# $NetBSD: options.mk,v 1.2 2022/07/07 13:40:40 thor Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.arpack-ng
PKG_SUPPORTED_OPTIONS=	mpi
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		mpi
.if !empty(PKG_OPTIONS:Mmpi)
PLIST.mpi=		yes
CMAKE_ARGS+=	-DMPI=on
.include "../../mk/mpi.buildlink3.mk"
.else
CMAKE_ARGS+=	-DMPI=off
.endif
