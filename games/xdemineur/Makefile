# $NetBSD: Makefile,v 1.29 2025/11/12 05:28:19 pgoyette Exp $
#

DISTNAME=	xdemineur-2.1.1
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Minesweeper game for the X Window System

USE_IMAKE=	YES

.include "../../devel/sysexits/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
