# $NetBSD: options.mk,v 1.1 2014/04/05 23:54:16 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.${GCC_PKGNAME}
PKG_SUPPORTED_OPTIONS=	gcc-inplace-math gcc-graphite
PKG_SUGGESTED_OPTIONS=	gcc-graphite

.if ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	gcc-inplace-math
.endif

###
### Determine if multilib is avalible.
###
MULTILIB_SUPPORTED?=	unknown
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
.  if exists(/usr/include/gnu/stubs-64.h) && \
     !exists(/usr/include/gnu/stubs-32.h)
MULTILIB_SUPPORTED=No
.  else
MULTILIB_SUPPORTED=Yes
.  endif
.endif
.if !empty(MULTILIB_SUPPORTED:M[Yy][Ee][Ss])
PKG_SUPPORTED_OPTIONS+=	gcc-multilib
PKG_SUGGESTED_OPTIONS+=	gcc-multilib
.endif

.include "../../mk/bsd.options.mk"

###
### Multilib Support
###
.if (!empty(MULTILIB_SUPPORTED:M[Yy][Ee][Ss]) && \
      empty(PKG_OPTIONS:Mgcc-multilib) ) || \
    !empty(MULTILIB_SUPPORTED:M[Nn][Oo])
CONFIGURE_ARGS+=	--disable-multilib
.endif

###
### Build math libraries in place
###
.if !empty(PKG_OPTIONS:Mgcc-inplace-math)
.  include "../../devel/gmp/inplace.mk"
.  include "../../math/mpcomplex/inplace.mk"
.  include "../../math/mpfr/inplace.mk"
.else
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
LIBS.SunOS+=		-lgmp
.  include "../../devel/gmp/buildlink3.mk"
.  include "../../math/mpcomplex/buildlink3.mk"
.  include "../../math/mpfr/buildlink3.mk"
.endif

###
### Graphite Support
###
.if !empty(PKG_OPTIONS:Mgcc-graphite)
CONFIGURE_ARGS+=	--with-cloog=${BUILDLINK_PREFIX.cloog}
CONFIGURE_ARGS+=	--enable-cloog-backend=isl
.include "../../math/cloog/buildlink3.mk"
.include "../../math/isl/buildlink3.mk"
.endif
