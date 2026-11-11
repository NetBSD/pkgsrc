# $NetBSD: Makefile,v 1.2 2026/11/11 11:53:53 wiz Exp $

DISTNAME=	OSL-1.15.7.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	OpenShadingLanguage
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/AcademySoftwareFoundation/OpenShadingLanguage
COMMENT=	Advanced shading language for production GI renderers
LICENSE=	modified-bsd

USE_TOOLS+=	bison flex gmake pkg-config
USE_LANGUAGES=	c c++

# Run oslc during build.
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=TRUE
CMAKE_CONFIGURE_ARGS+=	-DUSE_PYTHON=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_QT=OFF

PKGCONFIG_OVERRIDE+=	src/build-scripts/oslcomp.pc.in
PKGCONFIG_OVERRIDE+=	src/build-scripts/oslexec.pc.in
PKGCONFIG_OVERRIDE+=	src/build-scripts/oslquery.pc.in

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/build-scripts/serialize-bc.py
	${RM} -r ${DESTDIR}${PREFIX}/cmake/llvm_macros.cmake

.include "../../devel/cmake/build.mk"
.include "../../devel/robin-map/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../graphics/openimageio/buildlink3.mk"
.include "../../graphics/partio/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
