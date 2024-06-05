# $NetBSD: Makefile,v 1.12 2024/06/05 13:51:28 adam Exp $

DISTNAME=	libcerf-v2.4
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	devel math
MASTER_SITES=	https://jugit.fz-juelich.de/mlz/libcerf/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jugit.fz-juelich.de/mlz/libcerf
COMMENT=	Library providing efficient and accurate complex error functions
LICENSE=	mit

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_TOOLS+=		pod2man
PKGCONFIG_OVERRIDE=	libcerf.pc.in

TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
