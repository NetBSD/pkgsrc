# $NetBSD: Makefile,v 1.6 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=	tads23-unix
PKGNAME=	tads-3.0.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.tads.org/t3dl

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.tads.org/
COMMENT=	TADS compiler and interpreter

# for other OSs, enable appropriate Makefile sections
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}/tads
USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
BUILD_DIRS=	${WRKSRC}/tads2 ${WRKSRC}/tads3
MAKEFILE=	makefile
USE_LANGUAGES=	c c++

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
