# $NetBSD: Makefile,v 1.31 2013/01/26 21:37:40 adam Exp $

DISTNAME=	ImageViewer-0.6.3
PKGREVISION=	9
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nice.ch/~phip/softcorner.html
COMMENT=	GNUstep image display application

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
