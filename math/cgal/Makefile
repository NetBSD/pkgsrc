# $NetBSD: Makefile,v 1.44 2019/07/01 04:07:49 ryoon Exp $

DISTNAME=	CGAL-4.14
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=CGAL/}
GITHUB_RELEASE=	releases/${DISTNAME}

EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://www.cgal.org/
COMMENT=	Computational Geometry Algorithms Library
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++03
CMAKE_ARGS+=	-DCGAL_INSTALL_MAN_DIR=${PREFIX}/${PKGMANDIR}/man1

REPLACE_SH+=	scripts/cgal_create_CMakeLists
REPLACE_SH+=	scripts/cgal_create_cmake_script

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
