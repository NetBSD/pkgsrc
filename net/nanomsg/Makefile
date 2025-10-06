# $NetBSD: Makefile,v 1.9 2025/10/06 08:03:30 adam Exp $

DISTNAME=	nanomsg-1.2.2
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

# Fix for https://github.com/nanomsg/nanomsg/issues/1126
post-extract:
	${ECHO} ${PKGVERSION_NOREV} > ${WRKSRC}/.version

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
