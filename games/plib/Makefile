# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=	plib-1.6.0
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	Libraries for writing portable games/realtime interactive apps

USE_BUILDLINK3=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c++
CPPFLAGS+=	-Dunix=1

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
