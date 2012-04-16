# $NetBSD: options.mk,v 1.1.1.1 2012/04/16 04:27:18 sbd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.${GCC_PKGNAME}
PKG_SUPPORTED_OPTIONS=	nls gcc-inplace-math gcc-c++ gcc-fortran gcc-java \
			gcc-go gcc-objc gcc-objc++
PKG_SUGGESTED_OPTIONS=	gcc-c++ gcc-fortran gcc-go gcc-objc gcc-objc++

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	nls gcc-java
.elif ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	gcc-inplace-math
.else
PKG_SUGGESTED_OPTIONS+= gcc-java
.endif

###
### Determine if multilib is avalible.
###
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) && \
     exists(/usr/include/gnu/stubs-64.h) && \
    !exists(/usr/include/gnu/stubs-32.h)
MULTILIB_SUPPORTED=No
.endif
.if empty(MULTILIB_SUPPORTED:M[Nn][Oo])
PKG_SUPPORTED_OPTIONS+=  gcc-multilib
PKG_SUGGESTED_OPTIONS+=  gcc-multilib
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
.if empty(PKG_OPTIONS:Mgcc-multilib)
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
### Optional languages
### Ada could be added although there is a bootstrapping issue.  See
### ../gcc34-ada for guidance
###

.if !empty(PKG_OPTIONS:Mgcc-objc++)
.  if empty(PKG_OPTIONS:Mgcc-c++)
PKG_OPTIONS+=		gcc-c++
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
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/java-env.mk"
.endif

.if !empty(PKG_OPTIONS:Mgcc-go)
LANGS+=			go
.endif

.if !empty(PKG_OPTIONS:Mgcc-java) || !empty(PKG_OPTIONS:Mgcc-go)
.include "../../mk/pthread.buildlink3.mk"
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
