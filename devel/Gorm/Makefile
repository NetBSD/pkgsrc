# $NetBSD: Makefile,v 1.52 2013/01/26 21:37:17 adam Exp $

DISTNAME=	gorm-1.2.18
PKGNAME=	Gorm-1.2.18
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
