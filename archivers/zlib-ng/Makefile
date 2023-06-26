# $NetBSD: Makefile,v 1.2 2023/06/26 08:23:28 jperkin Exp $

DISTNAME=	zlib-ng-2.0.7
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=zlib-ng/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zlib-ng/zlib-ng/
COMMENT=	Replacement for zlib with optimizations for "next generation" systems
LICENSE=	zlib

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,${WRKSRC}/zlib-ng.map

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
TEST_TARGET=	test

PKGCONFIG_OVERRIDE+=	zlib.pc.cmakein

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
