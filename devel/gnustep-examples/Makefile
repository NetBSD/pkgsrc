# $NetBSD: Makefile,v 1.13 2004/09/27 01:14:18 rh Exp $
#

DISTNAME=	gnustep-examples-1.0.0
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Some GUI programming examples for GNUstep

USE_BUILDLINK3=	yes
USE_X11=	yes
NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
