# $NetBSD: options.mk,v 1.3 2011/07/07 12:26:45 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.speex
PKG_SUPPORTED_OPTIONS=	fftw
PKG_OPTIONS_GROUP.i386=	simd
###
### XXX TODO: add logic for enabling arm, fixed point, and alternate fft
###	implementations, etc.
###
.include "../../mk/bsd.fast.prefs.mk"

.if defined(PKG_OPTIONS_GROUP.${MACHINE_ARCH})
PKG_OPTIONS_OPTIONAL_GROUPS+=	${MACHINE_ARCH}
.endif

.include "../../mk/bsd.options.mk"
###
### XXX	The configure script seems to detect sse based upon user-supplied
###	CFLAGS.  If this is indeed OK, then we should not explicitly
###	disable it, as people might be using devel/cpuflags, etc.
###
.if !empty(PKG_OPTIONS:Msimd)
CONFIGURE_ARGS+=	--enable-sse
#.else
#CONFIGURE_ARGS+=	--disable-sse
.endif

.if !empty(PKG_OPTIONS:Mfftw)
CONFIGURE_ARGS+=	--with-fft=gpl-fftw3
.  include "../../math/fftwf/buildlink3.mk"
.endif
