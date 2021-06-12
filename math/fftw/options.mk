# $NetBSD: options.mk,v 1.12 2021/06/12 07:30:23 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fftw
PKG_SUPPORTED_OPTIONS=	fftw-fortran openmp mpi simd

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:M*gcc*) || !empty(PKGSRC_COMPILER:M*clang*)
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
.  if !empty(MACHINE_ARCH:Mpowerpc*)
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
