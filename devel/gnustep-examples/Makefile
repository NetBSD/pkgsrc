# $NetBSD: Makefile,v 1.12 2004/09/24 01:56:54 rh Exp $
#

DISTNAME=	gnustep-examples-0.9.7
PKGREVISION=	9
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
