# $NetBSD: Makefile,v 1.19 2007/02/02 18:05:54 joerg Exp $
#

DISTNAME=	plib-1.6.0
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	Libraries for writing portable games/realtime interactive apps

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
CPPFLAGS+=	-Dunix=1

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
