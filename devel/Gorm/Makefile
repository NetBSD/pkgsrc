# $NetBSD: Makefile,v 1.44 2007/11/25 17:18:52 wiz Exp $

DISTNAME=	gorm-1.2.2
PKGNAME=	Gorm-1.2.2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep

#LICENSE=	gnu-gplv3

USE_LANGUAGES=	objc

BUILDLINK_API_DEPENDS.gnustep-base+=	gnustep-base>=1.11.1
BUILDLINK_API_DEPENDS.gnustep-gui+=	gnustep-gui>=0.10.1

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
