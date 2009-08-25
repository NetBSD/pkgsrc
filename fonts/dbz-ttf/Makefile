# $NetBSD: Makefile,v 1.18 2009/08/25 11:56:35 wiz Exp $
#

DISTNAME=	dbz
PKGNAME=	dbz-ttf-20050114
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.andrew.cmu.edu/~twm/fonts/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fonts.tom7.com/
COMMENT=	Divide By Zero TrueType fonts created by Tom Murphy 7
LICENSE=	dbz-ttf-license

RESTRICTED=	Resale prohibited.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_OPTS_ZIP=	-Laqo

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11=	YES
NO_BUILD=	YES
NO_CONFIGURE=	YES

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/dbz-ttf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKDIR}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
