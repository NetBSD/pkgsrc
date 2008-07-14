# $NetBSD: Makefile,v 1.14 2008/07/14 12:56:04 joerg Exp $
#

DISTNAME=	xpilot-4.5.4
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xpilotgame/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xpilot.org/
COMMENT=	Networked space battles for X11

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
