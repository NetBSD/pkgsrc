# $NetBSD: Makefile,v 1.4 2003/07/17 21:29:18 grant Exp $
#

DISTNAME=		ProjectCenter-0.3.2
PKGREVISION=				1
WRKSRC=			${WRKDIR}/ProjectCenter
CATEGORIES=		devel gnustep
MASTER_SITES=		${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnustep.org/experience/ProjectCenter.html
COMMENT=		GNUstep Integrated Developement Environment

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_X11=		yes
NO_CONFIGURE=		yes
MAKEFILE=		GNUmakefile

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
