# $NetBSD: Makefile,v 1.24 2011/12/22 18:21:38 drochner Exp $
#

DISTNAME=	plib-1.8.5
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	Libraries for writing portable games/realtime interactive apps

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
CPPFLAGS+=	-Dunix=1

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
