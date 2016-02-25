# $NetBSD: options.mk,v 1.12 2016/02/25 14:42:55 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc44
PKG_SUPPORTED_OPTIONS=	gcc-inplace-math nls gcc-c++ gcc-fortran gcc-java gcc-objc #gcc-ada
PKG_SUGGESTED_OPTIONS=	gcc-c++ gcc-fortran gcc-java gcc-objc

PKG_SUGGESTED_OPTIONS.NetBSD+=	nls
PKG_SUGGESTED_OPTIONS.SunOS+=	gcc-inplace-math

PKG_OPTIONS_LEGACY_VARS+=	BUILD_CXX:gcc-c++
PKG_OPTIONS_LEGACY_VARS+=	BUILD_FORTRAN:gcc-fortran
PKG_OPTIONS_LEGACY_VARS+=	BUILD_JAVA:gcc-java
PKG_OPTIONS_LEGACY_VARS+=	BUILD_OBJC:gcc-objc

.include "../../mk/bsd.options.mk"

###
### Build math libraries in place
###
.if !empty(PKG_OPTIONS:Mgcc-inplace-math)
.include "../../devel/gmp/inplace.mk"
.include "../../math/mpfr/inplace.mk"
.else
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.endif

###
### Native Language Support
###
.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--enable-nls
USE_TOOLS+=		msgfmt
MAKE_ENV+=		ICONVPREFIX=${BUILDLINK_PREFIX.iconv}
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

###
### Optional languages
### Ada could be added although there is a bootstrapping issue.  See
### ../gcc34-ada for guidance
###

LANGS=			c

.if !empty(PKG_OPTIONS:Mgcc-java)
.  if empty(PKG_OPTIONS:Mgcc-c++)
PKG_OPTIONS+=		gcc-c++
.  endif

LANGS+=			java
REPLACE_PYTHON=		libjava/contrib/aot-compile.in

USE_TOOLS+=		unzip zip:run
CONFIGURE_ARGS+=	--with-system-zlib

# ${WRKSRC}/gcc-4.4.1/libjava/contrib/aotcompile.py.in stores the path to
# a 'make' program so we need to make sure we give it the installed 'make' and not
# the tool wrapped one.
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
.endif

.if !empty(PKG_OPTIONS:Mgcc-c++)
LANGS+=			c++
USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--enable-__cxa_atexit
.endif

.if !empty(PKG_OPTIONS:Mgcc-fortran)
LANGS+=			fortran
.endif

.if !empty(PKG_OPTIONS:Mgcc-objc)
LANGS+=			objc
.endif

#.if !empty(PKG_OPTIONS:Mgcc-ada)
#LANGS+=		ada
#.endif
