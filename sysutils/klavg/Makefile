# $NetBSD: Makefile,v 1.10 2003/11/14 09:20:13 wiz Exp $
#

DISTNAME=	klavg-1.1
PKGREVISION=	3
WRKSRC=		${WRKDIR}/klavg
CATEGORIES=	kde sysutils
MASTER_SITES=	ftp://ftp.crocodile.org/pub/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.crocodile.org/software.html
COMMENT=	Xload for the KDE panel

USE_BUILDLINK2=	yes
USE_X11=	yes
MAKE_ENV+=	KDEDIR=${BUILDLINK_PREFIX.kdebase}

.include "../../x11/kdebase/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
