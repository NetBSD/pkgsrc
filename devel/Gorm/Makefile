# $NetBSD: Makefile,v 1.63 2017/04/22 21:03:29 adam Exp $

DISTNAME=	gorm-1.2.20
PKGNAME=	Gorm-1.2.20
PKGREVISION=	5
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
