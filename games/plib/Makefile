# $NetBSD: Makefile,v 1.3 2000/10/15 12:06:35 rh Exp $
#

DISTNAME=	plib-1.2.0
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://plib.sourceforge.net/

USE_X11=	YES
USE_MESA=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-Dunix=1 -I${X11PREFIX}/include -I${X11BASE}/include

.include "../../mk/bsd.pkg.mk"
