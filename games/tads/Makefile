# $NetBSD: Makefile,v 1.16 2013/10/10 18:27:37 roy Exp $
#

DISTNAME=	tads23-unix
PKGNAME=	tads-3.0.8
PKGREVISION=	2
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
BUILD_DIRS=	tads2 tads3
USE_LANGUAGES=	c c++

post-extract:
	${RM} ${WRKSRC}/tads3/BSD/wchar.h

#.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
