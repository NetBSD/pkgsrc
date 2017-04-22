# $NetBSD: Makefile,v 1.40 2017/04/22 21:03:37 adam Exp $

DISTNAME=	ImageViewer-0.6.3
PKGREVISION=	18
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
