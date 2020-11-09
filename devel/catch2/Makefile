# $NetBSD: Makefile,v 1.8 2020/11/09 14:25:55 wiz Exp $

DISTNAME=	Catch2-2.13.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=catchorg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/catchorg/Catch2/
COMMENT=	C++ header-only test framework for unit tests
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++14
USE_CMAKE=	yes
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBUILD_TESTING=OFF

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../mk/bsd.pkg.mk"
