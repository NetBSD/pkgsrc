# $NetBSD: Makefile,v 1.9 2003/07/21 16:49:59 martti Exp $
#

DISTNAME=	plib-1.2.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	Libraries for writing portable games/realtime interactive apps

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-Dunix=1

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
