# $NetBSD: Makefile,v 1.9 2004/03/09 23:32:59 snj Exp $
#

DISTNAME=	xbreaky-0.0.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://xbreaky.sourceforge.net/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://xbreaky.sourceforge.net/
COMMENT=	Breakout game for X11

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK3=	YES
USE_X11=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
