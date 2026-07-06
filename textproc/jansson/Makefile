# $NetBSD: Makefile,v 1.15 2026/07/06 05:38:50 wiz Exp $

DISTNAME=	jansson-2.15.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=akheron/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/akheron/jansson
COMMENT=	C library for encoding, decoding and manipulating JSON data
LICENSE=	mit

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
CMAKE_CONFIGURE_ARGS+=	-DJANSSON_BUILD_SHARED_LIBS=ON
# needs sphinx
CMAKE_CONFIGURE_ARGS+=	-DJANSSON_BUILD_DOCS=OFF
PKGCONFIG_OVERRIDE+=	jansson.pc.in
TEST_TARGET=		check
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
