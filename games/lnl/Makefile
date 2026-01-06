# $NetBSD: Makefile,v 1.9 2026/01/06 08:49:04 wiz Exp $

DISTNAME=	lnl-3.4.19
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_OSDN:=lnl/50524/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://lnl.osdn.jp/
COMMENT=	L&L - Labyrinths & Legends - Fantasy RPG
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

# not used
CHECK_PORTABILITY_SKIP=	sh/*

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
