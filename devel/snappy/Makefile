# $NetBSD: Makefile,v 1.14 2020/01/18 23:30:41 rillig Exp $

DISTNAME=	snappy-1.1.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://google.github.io/snappy/
COMMENT=	General purpose data compression library
LICENSE=	apache-2.0

GITHUB_TAG=	${PKGVERSION_NOREV}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
TEST_TARGET=		test
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
