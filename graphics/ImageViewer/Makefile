# $NetBSD: Makefile,v 1.27 2008/06/21 18:24:24 joerg Exp $

DISTNAME=	ImageViewer-0.6.3
PKGREVISION=	6
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nice.ch/~phip/softcorner.html
COMMENT=	GNUstep image display application

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
