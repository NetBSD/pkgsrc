# $NetBSD: Makefile,v 1.26 2008/06/21 22:43:21 joerg Exp $
#

DISTNAME=	gnustep-examples-1.0.0
PKGREVISION=	7
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Some GUI programming examples for GNUstep

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${PREFIX}/share/GNUstep/Local/

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
