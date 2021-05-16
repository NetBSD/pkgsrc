# $NetBSD: options.mk,v 1.9 2021/05/16 08:44:33 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fftw
# fftw (double) and fftwf (single) are always built, you can add
# fftwl (long) and fftwq (quad).
PKG_SUPPORTED_OPTIONS=	fftw-fortran openmp mpi fftw-long fftw-quad

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:M*gcc*) || !empty(PKGSRC_COMPILER:M*clang*)
PKG_SUPPORTED_OPTIONS+=	simd
.  if ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=	avx
.  endif
PKG_SUGGESTED_OPTIONS+=	simd
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavx)
GCC_REQD+=		4.9
.  for opt in avx avx2 avx512 avx-128-fma
FFTW_FLOAT_OPTS+=	--enable-${opt}
FFTW_DOUBLE_OPTS+=	--enable-${opt}
.  endfor
.endif

.if !empty(PKG_OPTIONS:Msimd)
# Generic compiler vector abstractions (GCC extension).
FFTW_FLOAT_OPTS+=	--enable-generic-simd128 --enable-generic-simd256
FFTW_DOUBLE_OPTS+=	--enable-generic-simd128 --enable-generic-simd256
.  if ${MACHINE_ARCH} == "powerpc"
FFTW_FLOAT_OPTS+=	--enable-altivec
.  endif
.  if ${MACHINE_ARCH} == "x86_64"
FFTW_FLOAT_OPTS+=	--enable-sse2
FFTW_DOUBLE_OPTS+=	--enable-sse2
.  endif
.endif

.if !empty(PKG_OPTIONS:Mfftw-fortran)
USE_LANGUAGES+=		fortran77
.else
CONFIGURE_ARGS+=	--disable-fortran
.endif

PLIST_VARS+=		omp
.if !empty(PKG_OPTIONS:Mopenmp)
PLIST.omp=		yes
CONFIGURE_ARGS+=	--enable-openmp
.endif

PLIST_VARS+=		mpi
.if !empty(PKG_OPTIONS:Mmpi)
PLIST.mpi=		yes
CONFIGURE_ARGS+=	--enable-mpi
.include "../../mk/mpi.buildlink3.mk"
.endif

PLIST_VARS+=		long
.if !empty(PKG_OPTIONS:Mfftw-long)
FFTW_PRECISION+=	long-double
PLIST.long=		yes
.endif

PLIST_VARS+=		quad
.if !empty(PKG_OPTIONS:Mfftw-quad)
FFTW_PRECISION+=	quad-precision
PLIST.quad=		yes
.endif
