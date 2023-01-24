# $NetBSD: Makefile,v 1.46 2023/01/24 18:36:20 wiz Exp $

DISTNAME=	taglib-1.13
CATEGORIES=	audio
MASTER_SITES=	http://taglib.github.io/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://taglib.github.io/
COMMENT=	Library for accessing id tags in various media files
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1

USE_LANGUAGES=	c c++11
GCC_REQD+=	4.7

CMAKE_ARGS=		-DWITH_MP4=ON -DWITH_ASF=ON
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	bindings/c/taglib_c.pc.cmake taglib.pc.cmake
REPLACE_SH=		taglib-config.cmake

SUBST_CLASSES+=		pc
SUBST_FILES.pc=		taglib-config.cmake
SUBST_STAGE.pc=		pre-configure
SUBST_SED.pc=		-e 's|-L\([ 	]*[^ 	]*\)|${COMPILER_RPATH_FLAG}\1 -L\1|g'
SUBST_MESSAGE.pc=	Fixing rpath in taglib-config.

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
TEST_TARGET=			test
CMAKE_ARGS+=			-DBUILD_TESTING=ON
.include "../../devel/cppunit/buildlink3.mk"
.else
CMAKE_ARGS+=			-DBUILD_TESTING=OFF
.endif

.include "../../mk/compiler.mk"
#
# depends on builtin functions which enabled with i486 and later with GCC.
#
.if ${OPSYS} == "NetBSD" && !empty(CC_VERSION:Mgcc-[4-9]*) && ${MACHINE_ARCH} == i386
GNU_ARCH.i386=		i486
CFLAGS+=		-march=i486
.endif

.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id				\
	  ${PREFIX}/lib/libtag.1.dylib			\
	  ${DESTDIR}${PREFIX}/lib/libtag.1.19.0.dylib
	install_name_tool -id				\
	  ${PREFIX}/lib/libtag_c.0.dylib		\
	  ${DESTDIR}${PREFIX}/lib/libtag_c.0.0.0.dylib  \
	  -change					\
	  lib/libtag.1.dylib				\
	  ${PREFIX}/lib/libtag.1.dylib
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
