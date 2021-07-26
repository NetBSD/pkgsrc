# $NetBSD: Makefile,v 1.3 2021/07/26 00:03:18 sjmulder Exp $

DISTNAME=	within-1.1.4
CATEGORIES=	sysutils parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/sjmulder/within
COMMENT=	Run a command in other directories
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
