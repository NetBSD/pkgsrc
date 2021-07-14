# $NetBSD: Makefile,v 1.10 2021/07/14 17:56:16 adam Exp $

DISTNAME=	oneTBB-2021.3.0
PKGNAME=	${DISTNAME:S/oneTBB-/threadingbuildingblocks-/}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=oneapi-src/}
GITHUB_PROJECT=	oneTBB
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.threadingbuildingblocks.org/
COMMENT=	Threading Buildling Blocks
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
CMAKE_ARGS+=	-DTBB_STRICT=OFF
TEST_TARGET=	test

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
