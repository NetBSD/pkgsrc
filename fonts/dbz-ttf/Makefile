# $NetBSD: Makefile,v 1.7 2003/04/17 15:42:02 salo Exp $
#

DISTNAME=	dbz
PKGNAME=	dbz-ttf-20020507
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.andrew.cmu.edu/~twm/fonts/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://fonts.tom7.com/
COMMENT=	Divide By Zero TrueType fonts created by Tom Murphy 7

DIST_SUBDIR=	${PKGNAME_NOREV}

LICENSE=	limited-redistribution
RESTRICTED=	Resale prohibited.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

USE_X11BASE=	YES
NO_BUILD=	YES
NO_CONFIGURE=	YES

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TrueType
DOCDIR=		${PREFIX}/share/doc/dbz-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA} ${WRKDIR}/*.ttf ${FONTS_TTF_DIRS}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${DOCDIR}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
