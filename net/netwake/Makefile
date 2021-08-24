# $NetBSD: Makefile,v 1.3 2021/08/24 01:49:39 sjmulder Exp $

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

LDFLAGS.SunOS+=	-lsocket

.include "../../mk/bsd.pkg.mk"
