# $NetBSD: Makefile,v 1.3 2025/03/05 10:51:11 adam Exp $

DISTNAME=	libaec-v1.1.3
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	archivers
MASTER_SITES=	https://gitlab.dkrz.de/k202009/libaec/-/archive/v${PKGVERSION_NOREV}/
		#https://gitlab.dkrz.de/k202009/libaec/-/archive/v1.1.3/libaec-v1.1.3.tar.bz2
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://gitlab.dkrz.de/k202009/libaec
COMMENT=	Adaptive entropy coding library
LICENSE=	2-clause-bsd

CONFLICTS=	szip-[0-9]*

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
TEST_TARGET=		test

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
