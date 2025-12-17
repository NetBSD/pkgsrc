# $NetBSD: Makefile,v 1.4 2025/12/17 16:13:27 sjmulder Exp $

DISTNAME=	within-1.1.4
CATEGORIES=	sysutils parallel
MASTER_SITES=	https://codeberg.org/sjmulder/within/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://codeberg.org/sjmulder/within
COMMENT=	Run a command in other directories
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
