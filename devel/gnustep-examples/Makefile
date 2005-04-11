# $NetBSD: Makefile,v 1.15 2005/04/11 21:45:24 tv Exp $
#

DISTNAME=	gnustep-examples-1.0.0
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Some GUI programming examples for GNUstep

USE_X11=	yes
NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
