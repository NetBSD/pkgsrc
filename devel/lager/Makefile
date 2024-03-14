# $NetBSD: Makefile,v 1.1 2024/03/14 19:20:29 markd Exp $

DISTNAME=	lager-0.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arximboldi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sinusoid.es/lager
COMMENT=	C++ library for value-oriented design using unidirectional data-flow
LICENSE=	boost-license

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-Dlager_BUILD_EXAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=	-Dlager_BUILD_TESTS=OFF

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
