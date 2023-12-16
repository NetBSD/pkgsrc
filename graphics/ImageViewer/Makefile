# $NetBSD: Makefile,v 1.57 2023/12/16 12:12:06 zafer Exp $

DISTNAME=	ImageViewer-0.6.3
PKGREVISION=	33
CATEGORIES=	graphics gnustep
MASTER_SITES=	https://nice.ch/~phip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nice.ch/~phip/softcorner.html
COMMENT=	GNUstep image display application
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
