# $NetBSD: Makefile,v 1.5 2004/01/24 13:30:56 grant Exp $
#

DISTNAME=	pag-0.91
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://pancake.host.sk/altres/src/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://pancake.host.sk/
COMMENT=	Platform Arcade Game

USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	yes
USE_NCURSES=	yes # missing function stdscr

ALL_TARGET=	compile

.include "../../devel/ncurses/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
