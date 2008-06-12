# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:30 joerg Exp $
#

DISTNAME=	pag-0.92
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://cvs.nopcode.org/

MAINTAINER=	pancake@phreaker.net
#HOMEPAGE=	http://pancake.host.sk/
COMMENT=	Platform Arcade Game

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_NCURSES=	yes # missing function stdscr

GNU_CONFIGURE=	yes

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
