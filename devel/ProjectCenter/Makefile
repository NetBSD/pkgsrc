# $NetBSD: Makefile,v 1.14 2004/09/24 01:56:54 rh Exp $

DISTNAME=	ProjectCenter-0.4.0
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/experience/ProjectCenter.html
COMMENT=	GNUstep Integrated Development Environment

USE_BUILDLINK3=		yes
USE_X11=		yes
NO_CONFIGURE=		yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
