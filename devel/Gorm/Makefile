# $NetBSD: Makefile,v 1.38 2006/07/21 06:34:13 rillig Exp $

DISTNAME=	Gorm-1.0.8
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep

USE_LANGUAGES=	c objc

BUILDLINK_API_DEPENDS.gnustep-base+=	gnustep-base>=1.11.1
BUILDLINK_API_DEPENDS.gnustep-gui+=	gnustep-gui>=0.10.1

NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
