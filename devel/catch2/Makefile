# $NetBSD: Makefile,v 1.12 2022/10/17 12:10:39 adam Exp $

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
USE_LANGUAGES=	c c++14
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBUILD_TESTING=OFF

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../mk/bsd.pkg.mk"
