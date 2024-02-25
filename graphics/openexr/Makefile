# $NetBSD: Makefile,v 1.59 2024/02/25 15:56:52 wiz Exp $

DISTNAME=	openexr-3.2.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=openexr/}
GITHUB_PROJECT=	openexr
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++14

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	cmake/OpenEXR.pc.in

PTHREAD_OPTS=	require

# https://github.com/AcademySoftwareFoundation/openexr/issues/1594
CMAKE_ARGS+=	-DBUILD_TESTING=OFF

CHECK_PORTABILITY_SKIP+=	Contrib/DtexToExr/bootstrap
CHECK_PORTABILITY_SKIP+=	share/util/reformat.sh

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libdeflate/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
