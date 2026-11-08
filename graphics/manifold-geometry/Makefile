# $NetBSD: Makefile,v 1.1 2026/11/08 14:53:40 ryoon Exp $
DISTNAME=	manifold-3.5.4
PKGNAME=	${DISTNAME:S/manifold-/manifold-geometry-/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=elalish/}
GITHUB_PROJECT=	manifold
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/elalish/manifold/
COMMENT=	Geometry library on manifold triangle meshes
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	cmake/manifold.pc.in

# For tests
ALL_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/samples:${WRKSRC}/${CMAKE_BUILD_DIR}/bindings/c:${WRKSRC}/${CMAKE_BUILD_DIR}/src

.include "../../devel/cmake/build.mk"
.include "../../cad/clipper2/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
