# $NetBSD: Makefile,v 1.5 2003/12/05 10:33:34 adam Exp $
#

DISTNAME=	ProjectCenter-0.3.6
WRKSRC=		${WRKDIR}/ProjectCenter
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/experience/ProjectCenter.html
COMMENT=	GNUstep Integrated Developement Environment

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
NO_CONFIGURE=		YES
MAKEFILE=		GNUmakefile

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
