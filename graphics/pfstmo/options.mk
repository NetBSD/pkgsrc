# $NetBSD: options.mk,v 1.1.1.1 2009/01/18 12:48:19 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pfstmo
PKG_SUPPORTED_OPTIONS=	fftw gsl
PKG_SUGGESTED_OPTIONS=	fftw

PLIST_VARS+=	gsl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfftw)
.include "../../math/fftwf/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgsl)
.include "../../math/gsl/buildlink3.mk"
PLIST.gsl=	yes
.endif
