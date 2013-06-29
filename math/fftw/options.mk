# $NetBSD: options.mk,v 1.1 2013/06/29 18:59:43 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fftw
PKG_SUPPORTED_OPTIONS=	fftw-fortran
# Enable fortran support by default on platforms supported by lang/g95.
.if (!empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64) || \
	!empty(MACHINE_ARCH:Mia64) || !empty(MACHINE_ARCH:Mpowerpc*) || \
	!empty(MACHINE_ARCH:Mhppa) || !empty(MACHINE_ARCH:Msparc*) || \
	!empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mmips*))
PKG_SUGGESTED_OPTIONS=	fftw-fortran
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfftw-fortran)
USE_LANGUAGES+=		fortran77
.else
CONFIGURE_ARGS+=	--disable-fortran
.endif
