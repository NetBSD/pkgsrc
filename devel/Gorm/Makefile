# $NetBSD: Makefile,v 1.18 2004/08/18 14:02:44 adam Exp $

DISTNAME=	Gorm-0.7.7
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep

USE_BUILDLINK3=	yes
USE_X11=	yes
NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
