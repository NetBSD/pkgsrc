# $NetBSD: Makefile,v 1.12 2004/04/11 00:12:19 rh Exp $
#

DISTNAME=	ProjectCenter-0.3.6
PKGREVISION=	4
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/experience/ProjectCenter.html
COMMENT=	GNUstep Integrated Development Environment

WRKSRC=		${WRKDIR}/ProjectCenter
USE_BUILDLINK3=	yes
USE_X11=	yes
NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
