# $NetBSD: Makefile,v 1.11 2004/03/19 02:25:28 xtraeme Exp $
#

DISTNAME=	plib-1.6.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	Libraries for writing portable games/realtime interactive apps

USE_BUILDLINK3=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-Dunix=1

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
