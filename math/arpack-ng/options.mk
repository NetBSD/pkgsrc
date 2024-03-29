# $NetBSD: options.mk,v 1.3 2023/05/31 21:35:31 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.arpack-ng
PKG_SUPPORTED_OPTIONS=	mpi

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
