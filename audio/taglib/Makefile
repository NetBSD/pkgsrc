# $NetBSD: Makefile,v 1.29 2012/10/02 23:48:10 asau Exp $
#

DISTNAME=	taglib-1.8
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

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
