# $NetBSD: Makefile,v 1.6 2003/07/17 21:37:03 grant Exp $
#

DISTNAME=	geoslab703-ttf-20010522
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.will-harris.com/fonts/
DISTFILES=	geo703l.ttf geo703li.ttf

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.will-harris.com/fonts/freefonts.htm
COMMENT=	Free TrueType fonts from Bitstream, useful for web viewing

DIST_SUBDIR=	geoslab703-ttf
EXTRACT_ONLY=	# empty

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TrueType

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA} ${_DISTDIR}/*.ttf ${FONTS_TTF_DIRS}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
