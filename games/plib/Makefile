# $NetBSD: Makefile,v 1.5 2001/06/11 06:34:33 jlam Exp $
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
CPPFLAGS+=	-Dunix=1 -I${X11PREFIX}/include -I${X11BASE}/include

.include "../../mk/bsd.pkg.mk"
