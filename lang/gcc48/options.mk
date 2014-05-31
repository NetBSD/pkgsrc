# $NetBSD: options.mk,v 1.6 2014/05/31 13:06:25 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc48
PKG_SUPPORTED_OPTIONS=	nls gcc-inplace-math gcc-graphite gcc-java
PKG_SUGGESTED_OPTIONS=	gcc-graphite gcc-inplace-math

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	nls
#.elif ${OPSYS} == "SunOS"
#PKG_SUGGESTED_OPTIONS+=	gcc-inplace-math
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgcc-java)
.include "../../lang/gcc48/java.mk"
PLIST.java=			yes
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
.  if ${PKGPATH} == "lang/gcc48-cc++"
PLIST_SRC+=		${PLIST_SRC_DFLT} PLIST.nls
.  endif
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
ISL12=				isl-0.12.2
SITES.${ISL12}.tar.bz2=		${MASTER_SITE_GNU:=gcc/infrastructure/}
CLOOG18=			cloog-0.18.1
SITES.${CLOOG18}.tar.gz=	${MASTER_SITE_GNU:=gcc/infrastructure/}
DISTFILES+=			${ISL12}.tar.bz2 ${CLOOG18}.tar.gz
EXTRACT_ONLY+=			${ISL12}.tar.bz2 ${CLOOG18}.tar.gz
post-extract-graphite:
	${MV} ${WRKDIR}/${ISL12} ${WRKSRC}/isl
	${MV} ${WRKDIR}/${CLOOG18} ${WRKSRC}/cloog
.else
CONFIGURE_ARGS+=		--without-cloog --without-isl
.endif

.include "../../mk/bsd.options.mk"
