# $NetBSD: Makefile,v 1.7 2003/03/09 19:46:53 jschauma Exp $
#

DISTNAME=	plib-1.2.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	libraries for writing portable games/realtime interactive apps

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-Dunix=1

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
