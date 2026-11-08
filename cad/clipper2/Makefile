# $NetBSD: Makefile,v 1.2 2026/11/08 16:10:00 ryoon Exp $

DISTNAME=	Clipper2_2.0.1
PKGNAME=	${DISTNAME:S/Clipper2_/clipper2-/:tl}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=AngusJohnson/}
GITHUB_PROJECT=	Clipper2
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/PolyClipping/Clipper2
COMMENT=	Library performs operations on polygons
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/CPP

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_EXTERNAL_GTEST=ON

# For tests
ALL_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}

.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
