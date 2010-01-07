# $NetBSD: Makefile,v 1.15 2010/01/07 15:22:49 is Exp $
#

DISTNAME=	xpilot-4.5.4
PKGREVISION=	3
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
