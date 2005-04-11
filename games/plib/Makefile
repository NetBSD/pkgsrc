# $NetBSD: Makefile,v 1.14 2005/04/11 21:45:56 tv Exp $
#

DISTNAME=	plib-1.6.0
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	Libraries for writing portable games/realtime interactive apps

USE_X11=	YES
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c++
CPPFLAGS+=	-Dunix=1

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
