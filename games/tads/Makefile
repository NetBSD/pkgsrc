# $NetBSD: Makefile,v 1.14 2012/12/12 10:44:09 wiz Exp $
#

DISTNAME=	tads23-unix
PKGNAME=	tads-3.0.8
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.tads.org/t3dl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tads.org/
COMMENT=	TADS compiler and interpreter

# for other OSs, enable appropriate Makefile sections
ONLY_FOR_PLATFORM=	NetBSD-*-*

DIST_SUBDIR=	${PKGNAME_NOREV}-1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=	yes
BUILD_DIRS=	${WRKSRC}/tads2 ${WRKSRC}/tads3
USE_LANGUAGES=	c c++

post-extract:
	${RM} ${WRKSRC}/tads3/BSD/wchar.h

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
