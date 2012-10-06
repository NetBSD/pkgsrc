# $NetBSD: Makefile,v 1.4 2012/10/06 11:54:46 asau Exp $

DISTNAME=	lnl-3.4.19
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=lnl/50524/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lnl.sourceforge.jp/
COMMENT=	L&L - Labyrinths & Legends - Fantasy RPG
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

# not used
CHECK_PORTABILITY_SKIP=	sh/*

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
