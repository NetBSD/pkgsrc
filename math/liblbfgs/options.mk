# $NetBSD: options.mk,v 1.3 2024/05/23 22:08:49 cheusov Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liblbfgs

.include "../../mk/bsd.prefs.mk"

PKG_SUPPORTED_OPTIONS=	simd

.if ${MACHINE_ARCH} == "x86_64"
PKG_SUGGESTED_OPTIONS=	simd
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msimd)
CONFIGURE_ARGS+=	--enable-sse2
.endif
