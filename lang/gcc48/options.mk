# $NetBSD: options.mk,v 1.5 2014/04/23 12:53:36 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.${GCC_PKGNAME}
PKG_SUPPORTED_OPTIONS=	nls gcc-inplace-math gcc-graphite gcc-java
PKG_SUGGESTED_OPTIONS=	gcc-graphite

.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Mgcc-java)
.include "../../lang/gcc48/java.mk"
PKG_SUGGESTED_OPTIONS+=		gcc-java
PLIST.java=			yes
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	nls
.elif ${OPSYS} == "SunOS"
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
### Native Language Support
###
.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=		msgfmt
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
MAKE_ENV+=		ICONVPREFIX=${BUILDLINK_PREFIX.iconv}
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

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

.include "../../mk/bsd.options.mk"
