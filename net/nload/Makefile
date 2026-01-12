# $NetBSD: Makefile,v 1.11 2026/01/12 06:50:27 wiz Exp $

DISTNAME=		nload-0.7.4
PKGREVISION=		4
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nload/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://www.roland-riegel.de/nload/
COMMENT=		Monitoring network traffic and bandwidth usage
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
MANCOMPRESSED=		yes
GNU_CONFIGURE=		yes
FAKE_NCURSES=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
