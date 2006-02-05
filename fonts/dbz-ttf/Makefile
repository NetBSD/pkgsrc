# $NetBSD: Makefile,v 1.14 2006/02/05 23:09:09 joerg Exp $
#

DISTNAME=	dbz
PKGNAME=	dbz-ttf-20050114
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.andrew.cmu.edu/~twm/fonts/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fonts.tom7.com/
COMMENT=	Divide By Zero TrueType fonts created by Tom Murphy 7

DIST_SUBDIR=	${PKGNAME_NOREV}

LICENSE=	dbz-ttf-license
RESTRICTED=	Resale prohibited.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

USE_X11=	YES
NO_BUILD=	YES
NO_CONFIGURE=	YES

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/dbz-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKDIR}/*.ttf ${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
