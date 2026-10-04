# $NetBSD: Makefile,v 1.92 2026/10/04 15:46:30 wiz Exp $

DISTNAME=	openexr-3.5.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
PATCHFILES+=	925058c4b80aff5db8cf300bba622914f9a4d349.diff
PATCH_SITES+=	https://github.com/AcademySoftwareFoundation/openexr/commit/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17 filesystem

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	cmake/OpenEXR.pc.in

PTHREAD_OPTS=	require

# https://github.com/AcademySoftwareFoundation/openexr/issues/1594
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

CHECK_PORTABILITY_SKIP+=	Contrib/DtexToExr/bootstrap
CHECK_PORTABILITY_SKIP+=	share/util/reformat.sh

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libdeflate/buildlink3.mk"
.include "../../graphics/OpenJPH/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
