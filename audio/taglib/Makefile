# $NetBSD: Makefile,v 1.30 2012/12/17 11:10:42 obache Exp $
#

DISTNAME=	taglib-1.8
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/taglib/taglib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://taglib.github.com/
COMMENT=	Library for accessing id tags in various media files
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1

USE_LANGUAGES=		c c++

USE_CMAKE=		YES
CMAKE_ARGS=		-DWITH_MP4=ON -DWITH_ASF=ON
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	bindings/c/taglib_c.pc.cmake taglib.pc.cmake
REPLACE_SH=		taglib-config.cmake

SUBST_CLASSES+=		pc
SUBST_FILES.pc=		taglib-config.cmake
SUBST_STAGE.pc=		pre-configure
SUBST_SED.pc=		-e 's|-L\([ 	]*[^ 	]*\)|${COMPILER_RPATH_FLAG}\1 -L\1|g'
SUBST_MESSAGE.pc=	Fixing rpath in taglib-config.

.include "../../mk/compiler.mk"
#
# depends on builtin functions which enabled with i486 and later with GCC.
#
.if ${OPSYS} == "NetBSD" && && !empty(CC_VERSION:M[4-9]*) && !empty(MACHINE_ARCH:Mi386)
GNU_ARCH.i386=		i486
CFLAGS+=		-march=i486
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
