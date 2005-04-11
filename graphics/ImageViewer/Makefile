# $NetBSD: Makefile,v 1.15 2005/04/11 21:46:00 tv Exp $

DISTNAME=	ImageViewer-0.6.3
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nice.ch/~phip/softcorner.html
COMMENT=	GNUstep image display application

NO_CONFIGURE=		yes
USE_X11=		yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
