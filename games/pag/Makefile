# $NetBSD: Makefile,v 1.4 2003/09/28 09:13:57 jlam Exp $
#

DISTNAME=	pag-0.91
PKGREVISION=	1
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
