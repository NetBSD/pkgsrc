# $NetBSD: options.mk,v 1.1 2010/03/14 14:19:19 martin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mpg123
PKG_OPTIONS_OPTIONAL_GROUPS=	fpu
PKG_SUPPORTED_OPTIONS=		mpg123-fifo
PKG_SUGGESTED_OPTIONS+=		mpg123-fifo

.include "../../mk/bsd.fast.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
PKG_OPTIONS_GROUP.fpu=		mpg123-x86-dither mpg123-with-fpu
PKG_SUGGESTED_OPTIONS+=		mpg123-x86-dither
.elif (${MACHINE_ARCH} == "arm") || (${MACHINE_ARCH} == "arm32")
PKG_OPTIONS_GROUP.fpu=		mpg123-with-fpu
.elif (${MACHINE_ARCH} == "powerpc")
PKG_OPTIONS_GROUP.fpu=		mpg123-altivec mpg123-with-fpu
PKG_SUGGESTED_OPTIONS+=		mpg123-altivec
.else
PKG_OPTIONS_GROUP.fpu=		mpg123-with-fpu
PKG_SUGGESTED_OPTIONS+=		mpg123-with-fpu
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
.else
CONFIGURE_ARGS+=	--with-cpu=generic_nofpu
.endif

.if !empty(PKG_OPTIONS:Mmpg123-fifo)
CONFIGURE_ARGS+=	--enable-fifo=yes
.else
CONFIGURE_ARGS+=	--enable-fifo=no
.endif
