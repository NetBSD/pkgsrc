# $NetBSD: Makefile,v 1.4 2002/10/21 12:48:26 wiz Exp $
#

DISTNAME=	wmpload-0.9.4
CATEGORIES=	net x11
MASTER_SITES=	http://www.engr.utk.edu/~mdsmith/pload/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.engr.utk.edu/~mdsmith/pload/
COMMENT=	PPP monitor for X11, totals and current in/out rates in 64x64 cube

HAS_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_IMAKE=	YES
USE_X11BASE=	YES

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
