# $NetBSD: Makefile,v 1.9 2004/01/23 21:50:43 jmmv Exp $
#

DISTNAME=	ProjectCenter-0.3.6
PKGREVISION=			2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/experience/ProjectCenter.html
COMMENT=	GNUstep Integrated Developement Environment

WRKSRC=			${WRKDIR}/ProjectCenter
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
NO_CONFIGURE=		YES
MAKEFILE=		GNUmakefile

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
