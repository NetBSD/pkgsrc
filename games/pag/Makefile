# $NetBSD: Makefile,v 1.1.1.1 2003/07/11 22:53:24 zuntum Exp $
#

DISTNAME=	pag-0.91
CATEGORIES=	games
MASTER_SITES=	http://pancake.host.sk/altres/src/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://pancake.host.sk/
COMMENT=	Platform Arcade Game

USE_GMAKE=	yes
USE_BUILDLINK2=	yes
USE_NCURSES=	yes # missing function stdscr

ALL_TARGET=	compile

.include "../../devel/ncurses/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
