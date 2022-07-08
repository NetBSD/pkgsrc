# $NetBSD: options.mk,v 1.1 2022/07/08 19:47:59 thor Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.plumed
PKG_SUPPORTED_OPTIONS=	mpi
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpi)
# TODO: Have mpi.bl3 provide proper compiler names and use here.
# Needed for Intel support (mpiicpc).
CONFIGURE_ARGS+=	--enable-mpi CXX=mpicxx
.include "../../mk/mpi.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mpi
.endif
