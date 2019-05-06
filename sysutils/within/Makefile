# $NetBSD: Makefile,v 1.2 2019/05/06 09:17:13 sjmulder Exp $

DISTNAME=	within-1.1.3
CATEGORIES=	sysutils parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/sjmulder/within
COMMENT=	Run a command in other directories
LICENSE=	gnu-agpl-v3

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
