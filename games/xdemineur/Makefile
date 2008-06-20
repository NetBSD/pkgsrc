# $NetBSD: Makefile,v 1.27 2008/06/20 01:09:21 joerg Exp $
#

DISTNAME=	xdemineur-2.1.1
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Minesweeper game for the X Window System

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	YES

.include "../../devel/sysexits/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
