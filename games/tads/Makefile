# $NetBSD: Makefile,v 1.17 2015/01/04 06:58:44 dholland Exp $
#

DISTNAME=	tads23-unix
PKGNAME=	tads-3.0.8
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.tads.org/t3dl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tads.org/
COMMENT=	TADS compiler and interpreter

DIST_SUBDIR=	${PKGNAME_NOREV}-1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=	yes
BUILD_DIRS=	tads2 tads3
USE_LANGUAGES=	c c++
MAKE_ENV+=	PKGREVISION=${PKGREVISION} MAINTAINER=${MAINTAINER:Q}

post-extract:
	${RM} ${WRKSRC}/tads3/BSD/wchar.h

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
