# $NetBSD: options.mk,v 1.7 2020/10/27 08:53:57 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mpg123
PKG_OPTIONS_OPTIONAL_GROUPS=	fpu
PKG_SUPPORTED_OPTIONS=		mpg123-fifo
PKG_SUGGESTED_OPTIONS+=		mpg123-fifo
PKG_OPTIONS_GROUP.fpu=		mpg123-with-fpu

.include "../../mk/bsd.fast.prefs.mk"

# x86-dither causes text relocations and doesn't work with the Sun linker
# Don't enable it by default.
.if ${MACHINE_ARCH} == "i386"
PKG_OPTIONS_GROUP.fpu+=		mpg123-x86-dither
.endif

.if ${MACHINE_ARCH} == "aarch64"
PKG_OPTIONS_GROUP.fpu+=		mpg123-neon64 mpg123-aarch64
PKG_SUGGESTED_OPTIONS+=		mpg123-aarch64
.elif ${MACHINE_ARCH} == "powerpc"
PKG_OPTIONS_GROUP.fpu+=		mpg123-altivec
PKG_SUGGESTED_OPTIONS+=		mpg123-altivec
.else
# Avoid using floating point on softfloat ARM.
.  if !(!empty(MACHINE_ARCH:M*arm*) && empty(MACHINE_ARCH:M*hf*))
PKG_SUGGESTED_OPTIONS+=		mpg123-with-fpu
.  endif
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpg123-with-fpu)
CONFIGURE_ARGS+=	--with-cpu=generic_fpu
.elif !empty(PKG_OPTIONS:Mmpg123-altivec)
CONFIGURE_ARGS+=	--with-cpu=altivec
.elif !empty(PKG_OPTIONS:Mmpg123-x86-dither)
CONFIGURE_ARGS+=	--with-cpu=x86_dither
.elif !empty(PKG_OPTIONS:Mmpg123-altivec)
CONFIGURE_ARGS+=	--with-cpu=altivec
.elif !empty(PKG_OPTIONS:Mmpg123-neon64)
CONFIGURE_ARGS+=	--with-cpu=neon64
.elif !empty(PKG_OPTIONS:Mmpg123-aarch64)
CONFIGURE_ARGS+=	--with-cup=aarch64
.else
CONFIGURE_ARGS+=	--with-cpu=generic_nofpu
.endif

.if !empty(PKG_OPTIONS:Mmpg123-fifo)
CONFIGURE_ARGS+=	--enable-fifo=yes
.else
CONFIGURE_ARGS+=	--enable-fifo=no
.endif
