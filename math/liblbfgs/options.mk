# $NetBSD: options.mk,v 1.2 2023/11/17 12:07:49 nros Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liblbfgs

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} =="i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS=	liblbfgs-sse2
.  if ${MACHINE_ARCH} == "x86_64"
PKG_SUGGESTED_OPTIONS=	liblbfgs-sse2
.  endif
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mliblbfgs-sse2)
CONFIGURE_ARGS+=	--enable-sse2
.endif
