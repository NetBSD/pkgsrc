# $NetBSD: Makefile,v 1.3 2003/07/13 13:51:01 wiz Exp $
#

DISTNAME=		ProjectCenter-0.3.2
PKGREVISION=				1
WRKSRC=			${WRKDIR}/ProjectCenter
CATEGORIES=		devel gnustep
MASTER_SITES=		${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=		tech-pkg@netbsd.org
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
