# $NetBSD: mpg123-options.mk,v 1.3 2012/09/26 13:20:12 jperkin Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpg123
PKG_SUPPORTED_OPTIONS=	inet6 debug
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "powerpc" || \
   (${MACHINE_ARCH} == "i386" && ${OPSYS} != "SunOS")
PKG_SUPPORTED_OPTIONS+=	simd
.elif !empty(MACHINE_ARCH:Marm*)
PKG_SUPPORTED_OPTIONS+=	mpg123-arm-fixed64
.endif

PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS:S/debug//}

.include "../../mk/bsd.options.mk"

SIMD_CONFIGURE_ARGS.powerpc=	altvec
SIMD_CONFIGURE_ARGS.i386=	x86_dither

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6=no
.endif

.if !empty(PKG_OPTIONS:Msimd)
CONFIGURE_ARGS+=	--with-cpu=${SIMD_CONFIGURE_ARGS.${MACHINE_ARCH}}
.elif !empty(PKG_OPTIONS:Mmpg123-arm-fixed64)
CONFIGURE_ARGS+=	--with-cpu=generic_nofpu
.else
CONFIGURE_ARGS+=	--with-cpu=generic_fpu
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes
.else
CONFIGURE_ARGS+=	--enable-debug=no
.endif
