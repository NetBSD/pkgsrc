# $NetBSD: Makefile,v 1.6 2004/04/18 07:14:19 snj Exp $
#

DISTNAME=	wmpload-0.9.4
CATEGORIES=	net x11
MASTER_SITES=	http://www.engr.utk.edu/~mdsmith/pload/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.engr.utk.edu/~mdsmith/pload/
COMMENT=	PPP monitor for X11, totals and current in/out rates in 64x64 cube

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_IMAKE=	YES
USE_X11BASE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
