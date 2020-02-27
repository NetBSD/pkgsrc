# $NetBSD: Makefile,v 1.6 2020/02/27 10:17:24 fcambus Exp $

DISTNAME=	ninvaders-0.1.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ninvaders/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ninvaders.sourceforge.net/
COMMENT=	Space invaders, curses style
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=	bin

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
