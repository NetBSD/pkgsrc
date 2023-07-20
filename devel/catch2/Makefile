# $NetBSD: Makefile,v 1.13 2023/07/20 21:47:47 nia Exp $

DISTNAME=	Catch2-2.13.10
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=catchorg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/catchorg/Catch2
COMMENT=	C++ header-only test framework for unit tests
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBUILD_TESTING=OFF

USE_CXX_FEATURES+=	c++11

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../mk/bsd.pkg.mk"
