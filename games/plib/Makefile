# $NetBSD: Makefile,v 1.4 2001/02/16 15:10:56 wiz Exp $
#

DISTNAME=	plib-1.2.0
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	libraries for writing portable games/realtime interactive apps

USE_X11=	YES
USE_MESA=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-Dunix=1 -I${X11PREFIX}/include -I${X11BASE}/include

.include "../../mk/bsd.pkg.mk"
