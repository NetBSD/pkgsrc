# $NetBSD: Makefile,v 1.2 2021/08/06 04:04:59 sjmulder Exp $

DISTNAME=	netwake-0.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/sjmulder/netwake
COMMENT=	Wake-on-LAN utility with lookup file support
LICENSE=	2-clause-bsd

BUILD_DIRS=	cli

MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
