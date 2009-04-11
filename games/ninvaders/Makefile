# $NetBSD: Makefile,v 1.1.1.1 2009/04/11 18:00:42 snj Exp $

DISTNAME=	ninvaders-0.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ninvaders/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ninvaders.sourceforge.net/
COMMENT=	Space invaders, curses style

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
