# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:48 tv Exp $
#

DISTNAME=	ImageViewer-0.6.2
PKGREVISION=	2
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nice.ch/~phip/softcorner.html\#img
COMMENT=	GNUstep image display application

WRKSRC=		${WRKDIR}/ImageViewer
NO_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_X11=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
