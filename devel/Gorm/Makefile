# $NetBSD: Makefile,v 1.32 2006/02/05 23:08:38 joerg Exp $

DISTNAME=	Gorm-1.0.4
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep

BUILDLINK_DEPENDS.gnustep-base+=	gnustep-base>=1.11.1
BUILDLINK_DEPENDS.gnustep-gui+=		gnustep-gui>=0.10.1

NO_CONFIGURE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
