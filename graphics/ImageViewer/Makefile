# $NetBSD: Makefile,v 1.10 2004/03/26 02:27:40 wiz Exp $
#

DISTNAME=	ImageViewer-0.6.0
PKGREVISION=	5
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nice.ch/~phip/softcorner.html\#img
COMMENT=	GNUstep image display application

WRKSRC=		${WRKDIR}/ImageViewer
NO_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES
MAKEFILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
