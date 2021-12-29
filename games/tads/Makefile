# $NetBSD: Makefile,v 1.20 2021/12/29 09:36:37 dholland Exp $
#

DISTNAME=	tads23-unix
PKGNAME=	tads-3.0.8
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.tads.org/t3dl/
DIST_SUBDIR=	${PKGNAME_NOREV}-1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tads.org/
COMMENT=	TADS compiler and interpreter

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=	yes
BUILD_DIRS=	tads2 tads3
USE_LANGUAGES=	c c++
MAKE_ENV+=	PKGREVISION=${PKGREVISION} MAINTAINER=${MAINTAINER:Q}

post-extract:
	${RM} ${WRKSRC}/tads3/BSD/wchar.h

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
