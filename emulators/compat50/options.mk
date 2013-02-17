# $NetBSD: options.mk,v 1.1 2013/02/17 17:24:07 spz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compat50
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "sparc64" || ${MACHINE_ARCH} == "x86_64"
     DEPENDS+=	compat50-x11>=5.0:../../emulators/compat50-x11
.  endif
.endif
