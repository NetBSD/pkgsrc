# $NetBSD: Makefile,v 1.8 2004/03/08 19:40:39 jmmv Exp $
#

DISTNAME=	xbreaky-0.0.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://xbreaky.sourceforge.net/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://xbreaky.sourceforge.net/
COMMENT=	Breakout game for X11

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
