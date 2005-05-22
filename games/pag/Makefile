# $NetBSD: Makefile,v 1.10 2005/05/22 20:08:02 jlam Exp $
#

DISTNAME=	pag-0.91
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://pancake.host.sk/altres/src/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://pancake.host.sk/
COMMENT=	Platform Arcade Game

USE_TOOLS+=	gmake
USE_NCURSES=	yes # missing function stdscr

BUILD_TARGET=	compile

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
