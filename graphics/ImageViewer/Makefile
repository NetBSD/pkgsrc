# $NetBSD: Makefile,v 1.7 2004/01/20 12:18:15 agc Exp $
#

DISTNAME=	ImageViewer-0.6.0
PKGREVISION=	3
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nice.ch/~phip/softcorner.html\#img
COMMENT=	GNUstep image display application

WRKSRC=		${WRKDIR}/ImageViewer
NO_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
MAKEFILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
