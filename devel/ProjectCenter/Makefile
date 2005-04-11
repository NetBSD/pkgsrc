# $NetBSD: Makefile,v 1.18 2005/04/11 21:45:17 tv Exp $

DISTNAME=	ProjectCenter-0.4.2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/experience/ProjectCenter.html
COMMENT=	GNUstep Integrated Development Environment

USE_X11=		yes
NO_CONFIGURE=		yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
