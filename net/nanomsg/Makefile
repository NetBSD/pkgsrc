# $NetBSD: Makefile,v 1.7 2024/02/04 18:44:40 adam Exp $

DISTNAME=	nanomsg-1.2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nanomsg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nanomsg.org/
COMMENT=	Scalability protocols library
LICENSE=	x11

USE_LANGUAGES=	c

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
TEST_TARGET=	test

PKGCONFIG_OVERRIDE+=	src/pkgconfig.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
