# $NetBSD: Makefile,v 1.42 2019/06/22 05:54:27 mef Exp $

VERSION=	4.14
DISTNAME=	CGAL-${VERSION}
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=CGAL/}
GITHUB_RELEASE=	releases/CGAL-${VERSION}

EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://www.cgal.org/
COMMENT=	Computational Geometry Algorithms Library
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++03
# CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR}  # default, but not effective now
# CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:STRING=${PKGMANDIR}
# CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PKGMANDIR}		# neither one work

REPLACE_BASH+=	scripts/cgal_create_CMakeLists
REPLACE_BASH+=	scripts/cgal_create_cmake_script

pre-install:
	find ${WRKSRC} -name \*.orig -exec rm {} \;

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
