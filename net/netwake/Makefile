# $NetBSD: Makefile,v 1.6 2025/12/17 22:59:58 wiz Exp $

DISTNAME=	netwake-0.4
CATEGORIES=	net
MASTER_SITES=	https://codeberg.org/sjmulder/netwake/releases/download/${PKGVERSION_NOREV}/
# remove on next update
DIST_SUBDIR=	netwake-0.4-codeberg

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://codeberg.org/sjmulder/netwake
COMMENT=	Wake-on-LAN utility with lookup file support
LICENSE=	2-clause-bsd

BUILD_DIRS=	cli

MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}

LDFLAGS.SunOS+=	-lsocket

.include "../../mk/bsd.pkg.mk"
