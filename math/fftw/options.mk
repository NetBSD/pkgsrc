# $NetBSD: options.mk,v 1.4 2021/04/29 23:30:15 thor Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fftw
# fftw (double) and fftwf (single) are always built, you can add
# fftwl (long) and fftwq (quad).
PKG_SUPPORTED_OPTIONS=	fftw-fortran openmp mpi fftw-long fftw-quad
# Enable fortran support by default on platforms supported by lang/g95.
.if (!empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64) || \
	!empty(MACHINE_ARCH:Mia64) || !empty(MACHINE_ARCH:Mpowerpc*) || \
	!empty(MACHINE_ARCH:Mhppa) || !empty(MACHINE_ARCH:Msparc*) || \
	!empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mmips*))
# ...but disable it until lang/g95 issue is resolved.
#PKG_SUGGESTED_OPTIONS=	fftw-fortran
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfftw-fortran)
USE_LANGUAGES+=		fortran77
.else
CONFIGURE_ARGS+=	--disable-fortran
.endif

PLIST_VARS+=	omp
.if !empty(PKG_OPTIONS:Mopenmp)
PLIST.omp=	yes
CONFIGURE_ARGS+=	--enable-openmp
.endif

PLIST_VARS+=	mpi
.if !empty(PKG_OPTIONS:Mmpi)
PLIST.mpi=	yes
CONFIGURE_ARGS+=	--enable-mpi
.include "../../mk/mpi.buildlink3.mk"
.endif

PLIST_VARS+=	long quad

.if !empty(PKG_OPTIONS:Mfftw-long)
FFTW_PRECISION+=	long-double
PLIST.long=	yes
.endif

.if !empty(PKG_OPTIONS:Mfftw-quad)
FFTW_PRECISION+=	quad-precision
PLIST.quad=	yes
.endif
