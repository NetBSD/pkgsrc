# $NetBSD: Makefile,v 1.7 2004/10/08 23:14:37 mycroft Exp $
#

DISTNAME=	tads23-unix
PKGNAME=	tads-3.0.7
CATEGORIES=	games
MASTER_SITES=	http://www.tads.org/t3dl

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.tads.org/
COMMENT=	TADS compiler and interpreter

# for other OSs, enable appropriate Makefile sections
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}/tads-3.0.7
USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
BUILD_DIRS=	${WRKSRC}/tads2 ${WRKSRC}/tads3
USE_LANGUAGES=	c c++

post-extract:
	rm ${WRKSRC}/tads3/BSD/wchar.h

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
