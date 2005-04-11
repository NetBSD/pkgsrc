# $NetBSD: Makefile,v 1.9 2005/04/11 21:45:56 tv Exp $
#

DISTNAME=	pag-0.91
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://pancake.host.sk/altres/src/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://pancake.host.sk/
COMMENT=	Platform Arcade Game

USE_GNU_TOOLS+=	make
USE_NCURSES=	yes # missing function stdscr

BUILD_TARGET=	compile

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
