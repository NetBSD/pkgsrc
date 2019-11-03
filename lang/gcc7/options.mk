# $NetBSD: options.mk,v 1.6 2019/11/03 19:04:00 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.${GCC_PKGNAME}
PKG_SUPPORTED_OPTIONS=	nls gcc-inplace-math gcc-c++ gcc-fortran \
			gcc-go gcc-objc gcc-objc++ gcc-graphite \
			always-libgcc
PKG_SUGGESTED_OPTIONS=	gcc-c++ gcc-fortran gcc-objc gcc-objc++ \
			gcc-graphite gcc-inplace-math

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS+=	nls
.endif

.include "../../mk/compiler.mk"
.if empty(PKGSRC_COMPILER:Mgcc)
PKG_SUGGESTED_OPTIONS+=			always-libgcc
.endif

PKG_SUGGESTED_OPTIONS.SunOS+=		always-libgcc

###
### Determine if multilib is avalible.
###
MULTILIB_SUPPORTED?=	unknown
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
.  if exists(/usr/include/x86_64-linux-gnu/gnu)
_GNU_INCLUDE_DIR=	/usr/include/x86_64-linux-gnu/gnu
.  else
_GNU_INCLUDE_DIR=	/usr/include/gnu
.  endif
.  if exists(${_GNU_INCLUDE_DIR}/stubs-64.h) && \
     !exists(${_GNU_INCLUDE_DIR}/stubs-32.h)
MULTILIB_SUPPORTED=	No
.  else
MULTILIB_SUPPORTED=	Yes
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
### Don't install libgcc if it's older than the system one
###
.if empty(PKG_OPTIONS:Malways-libgcc)

.  for _libdir_ in ${_OPSYS_LIB_DIRS}
.    if exists(${_libdir_})
BASE_LIBGCC!=			find ${_libdir_} -name libgcc_s.so
BASE_LIBGCC_MATCH_STRING!=	${ECHO} ${BASE_LIBGCC} ${GCC7_DIST_VERSION} | \
				${AWK} -f ../../mk/scripts/larger_symbol_version.awk
.      if ${BASE_LIBGCC_MATCH_STRING:Mnewer}
DELETE_INSTALLED_LIBGCC=	yes
.      endif
.    endif
.  endfor

.  if ${DELETE_INSTALLED_LIBGCC:Uno}
post-install:	delete-installed-libgcc

delete-installed-libgcc:
	${FIND} ${DESTDIR} -name 'libgcc_s.so*' -delete

.  endif

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
ISL=			isl-0.18
DISTFILES+=		${ISL}.tar.bz2
SITES.${ISL}.tar.bz2=	ftp://ftp.fu-berlin.de/unix/languages/gcc/infrastructure/
post-extract:
	${LN} -f -s ${WRKDIR}/${ISL} ${WRKSRC}/isl
.endif

###
### Optional languages
### Ada could be added although there is a bootstrapping issue.  See
### ../gcc34-ada for guidance
###
.if !empty(PKG_OPTIONS:Mgcc-objc++)
.  if empty(PKG_OPTIONS:Mgcc-c++)
PKG_OPTIONS+=		gcc-c++
.  endif
.  if empty(PKG_OPTIONS:Mgcc-objc)
PKG_OPTIONS+=		gcc-objc
.  endif
LANGS+=			obj-c++
.endif

.if !empty(PKG_OPTIONS:Mgcc-objc)
LANGS+=			objc
.endif

.if !empty(PKG_OPTIONS:Mgcc-go)
LANGS+=			go
.endif

.if !empty(PKG_OPTIONS:Mgcc-fortran)
LANGS+=			fortran
.endif

.if !empty(PKG_OPTIONS:Mgcc-c++)
LANGS+=			c++
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--with-gxx-include-dir=${GCC_PREFIX}/include/c++/
.else
CONFIGURE_ARGS+=	--disable-build-with-cxx
CONFIGURE_ARGS+=	--disable-build-poststage1-with-cxx
.endif
