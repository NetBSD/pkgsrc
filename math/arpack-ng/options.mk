# $NetBSD: options.mk,v 1.4 2024/08/25 06:18:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.arpack-ng
PKG_SUPPORTED_OPTIONS=	mpi

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		mpi
.if !empty(PKG_OPTIONS:Mmpi)
PLIST.mpi=		yes
CMAKE_CONFIGURE_ARGS+=	-DMPI=on
.include "../../mk/mpi.buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DMPI=off
.endif
