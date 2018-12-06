# $NetBSD: Makefile,v 1.1 2018/12/06 20:03:52 leot Exp $

DISTNAME=	within-1.1.3
CATEGORIES=	sysutils parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://github.com/sjmulder/within
COMMENT=	Run a command in other directories
LICENSE=	gnu-agpl-v3

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
