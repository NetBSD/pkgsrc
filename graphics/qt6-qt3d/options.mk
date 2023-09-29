# $NetBSD: options.mk,v 1.2 2023/09/29 21:12:14 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt6-qt3d
PKG_SUPPORTED_OPTIONS+=	avx

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
