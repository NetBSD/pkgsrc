# $NetBSD: options.mk,v 1.6 2023/01/29 09:03:15 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc9
PKG_SUPPORTED_OPTIONS=	nls gcc-inplace-math gcc-c++ gcc-fortran \
			gcc-go gcc-objc gcc-objc++ always-libgcc
PKG_SUGGESTED_OPTIONS=	nls gcc-inplace-math gcc-c++ gcc-fortran \
			gcc-objc gcc-objc++

.if ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	gcc-inplace-math always-libgcc
.endif

.include "../../mk/compiler.mk"
.if !${PKGSRC_COMPILER:Mgcc}
PKG_SUGGESTED_OPTIONS+=	always-libgcc
.endif

###
### Determine if multilib is avalible.
###
MULTILIB_SUPPORTED?=	unknown
.if ${MACHINE_PLATFORM:MLinux-*-x86_64}
.  if exists(/usr/include/x86_64-linux-gnu/gnu)
GCC9_INCLUDE_DIR=	/usr/include/x86_64-linux-gnu/gnu
.  else
GCC9_INCLUDE_DIR=	/usr/include/gnu
.  endif
.  if exists(${GCC9_INCLUDE_DIR}/stubs-64.h) && \
     !exists(${GCC9_INCLUDE_DIR}/stubs-32.h)
MULTILIB_SUPPORTED=	no
.  else
MULTILIB_SUPPORTED=	yes
.  endif
.  if ${MULTILIB_SUPPORTED} == yes
PKG_SUPPORTED_OPTIONS+=	gcc-multilib
PKG_SUGGESTED_OPTIONS+=	gcc-multilib
.  endif
.endif

.include "../../mk/bsd.options.mk"

###
### Don't install libgcc if it's older than the system one
###
.if !${PKG_OPTIONS:Malways-libgcc}

.  for dir in ${_OPSYS_LIB_DIRS}
.    if exists(${dir})
BASE_LIBGCC!=		find ${dir} -name libgcc_s.so
BASE_LIBGCC_MATCH_STRING!= \
			${ECHO} ${BASE_LIBGCC} ${GCC9_VERSION} \
			| ${AWK} -f ../../mk/scripts/larger_symbol_version.awk
.      if ${BASE_LIBGCC_MATCH_STRING:Mnewer}
DELETE_INSTALLED_LIBGCC=	yes
.      endif
.    endif
.  endfor

.  if ${DELETE_INSTALLED_LIBGCC:Uno} == "yes"
post-install: delete-installed-libgcc

delete-installed-libgcc: .PHONY
	${FIND} ${DESTDIR} -name 'libgcc_s.so*' -delete
.  endif
.endif

.if ${PLIST.libgcc:Uno} == "yes"
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/gcc9/lib
.endif

###
### Native Language Support
###
.if ${PKG_OPTIONS:Mnls}
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
.if ${MULTILIB_SUPPORTED} == no \
    || (${MULTILIB_SUPPORTED} == yes && !${PKG_OPTIONS:Mgcc-multilib})
CONFIGURE_ARGS+=	--disable-multilib
.endif

###
### Build math libraries in place
###
.if ${PKG_OPTIONS:Mgcc-inplace-math}
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

.if ${PKG_OPTIONS:Mgcc-objc++}
.  if !${PKG_OPTIONS:Mgcc-c++}
PKG_OPTIONS+=		gcc-c++
.  endif
.  if !${PKG_OPTIONS:Mgcc-objc}
PKG_OPTIONS+=		gcc-objc
.  endif
LANGS+=			obj-c++
.endif

.if ${PKG_OPTIONS:Mgcc-objc}
LANGS+=			objc
.endif

.if ${PKG_OPTIONS:Mgcc-go}
LANGS+=			go
.endif

.if ${PKG_OPTIONS:Mgcc-fortran}
LANGS+=			fortran
.endif

.if ${PKG_OPTIONS:Mgcc-c++}
LANGS+=			c++
USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--with-gxx-include-dir=${GCC9_PREFIX}/include/c++/
PLIST_SUBST+=		CXXINCDIR=${GCC9_SUBPREFIX}/include/c++
.else
CONFIGURE_ARGS+=	--disable-build-with-cxx
CONFIGURE_ARGS+=	--disable-build-poststage1-with-cxx
PLIST_SUBST+=		CXXINCDIR=${GCC9_SUBPREFIX}/include/c++/${GCC9_VERSION}
.endif
