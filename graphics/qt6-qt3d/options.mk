# $NetBSD: options.mk,v 1.1 2023/09/22 08:49:44 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt6-qt3d

PLIST_VARS+=	avx

.if ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=	avx
.endif

.include "../../mk/bsd.options.mk"

##
## Enable use of Advanced Vector Extensions (AVX) 2
## [Requires a Haswell processor (or higher)]
##
.if !empty(PKG_OPTIONS:Mavx)
CONFIGURE_ARGS+=	-qt3d-simd avx2
PLIST.avx=		yes
.else
CONFIGURE_ARGS+=	-qt3d-simd sse2
.endif
