# $NetBSD: Makefile,v 1.4 2004/04/25 11:48:31 dillo Exp $
#

DISTNAME=	tads23-unix
PKGNAME=	tads-3.0.5
CATEGORIES=	games
MASTER_SITES=	http://www.ifarchive.org/if-archive/programming/tads2/source/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.ifarchive.org/if-archive/programming/tads2/source/
COMMENT=	TADS compiler and interpreter

# for other OSs, enable appropriate Makefile sections
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}/tads
USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
BUILD_DIRS=	${WRKSRC}/tads2 ${WRKSRC}/tads3
MAKEFILE=	makefile

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
