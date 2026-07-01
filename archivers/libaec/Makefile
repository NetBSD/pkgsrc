# $NetBSD: Makefile,v 1.6 2026/07/01 09:41:44 wiz Exp $
#
# for bug reports, use https://github.com/Deutsches-Klimarechenzentrum/libaec

DISTNAME=	libaec-v1.1.3
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	archivers
MASTER_SITES=	https://gitlab.dkrz.de/dkrz-sw/libaec/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://gitlab.dkrz.de/dkrz-sw/libaec
COMMENT=	Adaptive entropy coding library
LICENSE=	2-clause-bsd

CONFLICTS=	szip-[0-9]*

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
TEST_TARGET=		test

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
