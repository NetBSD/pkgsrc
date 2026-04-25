# $NetBSD: options.mk,v 1.1 2026/04/25 22:03:11 alnsn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.souffle
PKG_SUPPORTED_OPTIONS=		openmp sqlite souffle-64bit
PKG_SUGGESTED_OPTIONS=		openmp sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenmp)
# required to find OpenMP_gomp_LIBRARY ("../../mk/openmp.mk" doesn't work)
.include "../../parallel/openmp/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DSOUFFLE_USE_OPENMP=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DSOUFFLE_USE_OPENMP=OFF
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite3/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DSOUFFLE_USE_SQLITE=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DSOUFFLE_USE_SQLITE=OFF
.endif

.if !empty(PKG_OPTIONS:Msouffle-64bit)
CMAKE_CONFIGURE_ARGS+=	-DSOUFFLE_DOMAIN_64BIT=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DSOUFFLE_DOMAIN_64BIT=OFF
.endif
