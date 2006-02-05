# $NetBSD: Makefile,v 1.16 2006/02/05 23:09:21 joerg Exp $
#

DISTNAME=	plib-1.6.0
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	Libraries for writing portable games/realtime interactive apps

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c++
CPPFLAGS+=	-Dunix=1

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
