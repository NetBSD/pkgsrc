# $NetBSD: Makefile,v 1.26 2008/01/18 05:06:38 tnn Exp $

DISTNAME=	ImageViewer-0.6.3
PKGREVISION=	5
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nice.ch/~phip/softcorner.html
COMMENT=	GNUstep image display application

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
