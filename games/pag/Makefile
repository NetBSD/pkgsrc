# $NetBSD: Makefile,v 1.11 2005/08/25 14:38:05 xtraeme Exp $
#

DISTNAME=	pag-0.92
CATEGORIES=	games
MASTER_SITES=	http://cvs.nopcode.org/

MAINTAINER=	pancake@phreaker.net
#HOMEPAGE=	http://pancake.host.sk/
COMMENT=	Platform Arcade Game

USE_TOOLS+=	gmake
USE_NCURSES=	yes # missing function stdscr

GNU_CONFIGURE=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
