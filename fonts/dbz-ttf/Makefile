# $NetBSD: Makefile,v 1.3 2002/06/15 13:01:49 wiz Exp $
#

DISTNAME=	dbz
PKGNAME=	dbz-ttf-20020507
CATEGORIES=	fonts
MASTER_SITES=	http://www.andrew.cmu.edu/~twm/fonts/
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://fonts.tom7.com/
COMMENT=	Divide By Zero TrueType fonts created by Tom Murphy 7

LICENSE=	limited-redistribution

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

USE_X11BASE=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType
DOCDIR=		${PREFIX}/share/doc/dbz-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
