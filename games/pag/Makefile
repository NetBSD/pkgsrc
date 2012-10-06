# $NetBSD: Makefile,v 1.16 2012/10/06 11:54:49 asau Exp $
#

DISTNAME=	pag-0.92
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://pancake.host.sk/
COMMENT=	Platform Arcade Game

USE_TOOLS+=	gmake
USE_NCURSES=	yes # missing function stdscr

GNU_CONFIGURE=	yes

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
