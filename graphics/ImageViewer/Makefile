# $NetBSD: Makefile,v 1.12 2004/09/24 01:56:54 rh Exp $
#

DISTNAME=	ImageViewer-0.6.2
PKGREVISION=	1
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
