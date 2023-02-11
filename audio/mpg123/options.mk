# $NetBSD: options.mk,v 1.11 2023/02/11 12:39:17 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mpg123
PKG_OPTIONS_OPTIONAL_GROUPS=	fpu
PKG_SUPPORTED_OPTIONS=		mpg123-fifo
PKG_SUGGESTED_OPTIONS+=		mpg123-fifo
PKG_OPTIONS_GROUP.fpu=		mpg123-with-fpu

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_CPU} == "aarch64"
PKG_OPTIONS_GROUP.fpu+=		mpg123-neon64 mpg123-aarch64
PKG_SUGGESTED_OPTIONS+=		mpg123-aarch64
.elif ${MACHINE_ARCH} == "powerpc"
PKG_OPTIONS_GROUP.fpu+=		mpg123-altivec
PKG_SUGGESTED_OPTIONS+=		mpg123-altivec
.else
# Avoid using floating point on softfloat ARM.
.  if !(${MACHINE_ARCH:M*arm*} && !${MACHINE_ARCH:M*hf*})
PKG_SUGGESTED_OPTIONS+=		mpg123-with-fpu
.  endif
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpg123-with-fpu)
CONFIGURE_ARGS+=	--with-cpu=generic_fpu
.elif !empty(PKG_OPTIONS:Mmpg123-altivec)
CONFIGURE_ARGS+=	--with-cpu=altivec
.elif !empty(PKG_OPTIONS:Mmpg123-neon64)
CONFIGURE_ARGS+=	--with-cpu=neon64
.elif !empty(PKG_OPTIONS:Mmpg123-aarch64)
CONFIGURE_ARGS+=	--with-cpu=aarch64
.else
CONFIGURE_ARGS+=	--with-cpu=generic_nofpu
.endif

.if !empty(PKG_OPTIONS:Mmpg123-fifo)
CONFIGURE_ARGS+=	--enable-fifo=yes
.else
CONFIGURE_ARGS+=	--enable-fifo=no
.endif
