# $NetBSD: Makefile,v 1.24 2006/12/27 13:37:37 joerg Exp $
#

DISTNAME=       xdemineur-2.1.1
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.babafou.eu.org/xdemineur/ \
		${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Minesweeper game for the X Window System

USE_IMAKE=	YES

.include "../../devel/sysexits/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
