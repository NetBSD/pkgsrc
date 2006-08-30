# $NetBSD: Makefile,v 1.40 2006/08/30 14:55:56 adam Exp $

DISTNAME=	gorm-1.1.0
PKGNAME=	Gorm-1.1.0
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep

USE_LANGUAGES=	objc

BUILDLINK_API_DEPENDS.gnustep-base+=	gnustep-base>=1.11.1
BUILDLINK_API_DEPENDS.gnustep-gui+=	gnustep-gui>=0.10.1

NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
