# $NetBSD: Makefile,v 1.36 2006/05/20 12:24:37 adam Exp $

DISTNAME=	Gorm-1.0.8
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep

BUILDLINK_API_DEPENDS.gnustep-base+=	gnustep-base>=1.11.1
BUILDLINK_API_DEPENDS.gnustep-gui+=	gnustep-gui>=0.10.1

NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
