# $NetBSD: Makefile,v 1.30 2008/06/21 18:52:21 joerg Exp $

DISTNAME=	ProjectCenter-0.4.3
PKGREVISION=	6
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/experience/ProjectCenter.html
COMMENT=	GNUstep Integrated Development Environment

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
