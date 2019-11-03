# $NetBSD: options.mk,v 1.3 2019/11/03 19:03:59 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.${GCC_PKGNAME}
PKG_SUPPORTED_OPTIONS=	nls gcc-inplace-math gcc-c++ gcc-fortran \
			gcc-go gcc-objc gcc-objc++ gcc-graphite gcc-java \
			always-libgcc
PKG_SUGGESTED_OPTIONS=	gcc-c++ gcc-fortran gcc-objc gcc-objc++ \
			gcc-graphite gcc-inplace-math

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	nls
.elif ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	nls
.elif ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	nls
.elif ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	gcc-inplace-math always-libgcc
.else
.endif

.include "../../mk/compiler.mk"
.if empty(PKGSRC_COMPILER:Mgcc)
PKG_SUGGESTED_OPTIONS+=			always-libgcc
.endif

###
### Determine if multilib is avalible.
###
MULTILIB_SUPPORTED?=	unknown
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
.  if exists(/usr/include/gnu/stubs-64.h) && \
     !exists(/usr/include/gnu/stubs-32.h)
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
BASE_LIBGCC_MATCH_STRING!=	${ECHO} ${BASE_LIBGCC} ${GCC6_DIST_VERSION} | \
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
ISL14 =		isl-0.14
SITES.${ISL14}.tar.bz2 = ${MASTER_SITE_GNU:=gcc/infrastructure/}
DISTFILES +=	${ISL14}.tar.bz2
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

.if !empty(PKG_OPTIONS:Mgcc-java)
.  if empty(PKG_OPTIONS:Mgcc-c++)
PKG_OPTIONS+=		gcc-c++
.  endif

LANGS+=			java

# Add the  Eclipse Java compiler for to parse `.java' source files.
ECJ_JAR=		ecj-4.5.jar
SITES.${ECJ_JAR}=	ftp://sourceware.org/pub/java/
DISTFILES+=		${ECJ_JAR}
CONFIGURE_ARGS+=	--with-ecj-jar=${DISTDIR:Q}/${ECJ_JAR:Q}

JAVA_NAME=		${GCC_PKGNAME}
JAVA_HOME=		${PREFIX}/java/${JAVA_NAME}
JAVA_WRAPPERS=		appletviewer jar jarsigner java javah keytool \
			native2ascii orbd rmic rmid rmiregistry serialver \
			tnameserv

JAVA_ARCH=		${MACHINE_ARCH:S/x86_64/amd64/}

PLIST_SRC+=		PLIST.java
PLIST_SUBST+=		JAVA_NAME=${JAVA_NAME:Q}
PLIST_SUBST+=		JAVA_ARCH=${JAVA_ARCH:Q}

# Create a JPackage compatible SDK environment.
CONFIGURE_ARGS+=	--enable-java-home
CONFIGURE_ARGS+=	--with-os-directory=${LOWER_OPSYS:Q}
CONFIGURE_ARGS+=	--with-arch-directory=${JAVA_ARCH:Q}
CONFIGURE_ARGS+=	--with-jvm-root-dir=${JAVA_HOME:Q}
CONFIGURE_ARGS+=	--with-java-home=${JAVA_HOME:Q}

REPLACE_PYTHON=		libjava/contrib/aot-compile.in

USE_TOOLS+=		unzip zip:run gmake:run
CONFIGURE_ARGS+=	--with-system-zlib

# libjava/contrib/aotcompile.py.in stores the path to a 'make' program so
# we need to make sure we give it the installed 'make' and not the tool
# wrapped one.
CONFIGURE_ENV+=		PKGSRC_MAKE=${TOOLS_PATH.gmake}
MAKE_ENV+=		PKGSRC_MAKE=${TOOLS_PATH.gmake}

# fastjar-0.93 from pkgsrc/archivers/fastjar seems to trigger a build
# failure (seen on NetBSD-5.0/i386) when building java.  So in case
# the fastjar package is installed, make sure the configure script
# doesn't pick it up.
CONFIGURE_ENV+=		JAR=no
MAKE_ENV+=		JAR=no
MAKE_ENV+=		ac_cv_prog_JAR=no

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/java-env.mk"
.endif

.if !empty(PKG_OPTIONS:Mgcc-go)
LANGS+=			go
.endif

.if !empty(PKG_OPTIONS:Mgcc-fortran)
LANGS+=			fortran
.endif

.if !empty(PKG_OPTIONS:Mgcc-c++)
LANGS+=			c++
USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--with-gxx-include-dir=${GCC_PREFIX}/include/c++/
.else
CONFIGURE_ARGS+=	--disable-build-with-cxx
CONFIGURE_ARGS+=	--disable-build-poststage1-with-cxx
.endif
