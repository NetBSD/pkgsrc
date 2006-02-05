# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:09 joerg Exp $
#

DISTNAME=	geoslab703-ttf-20010522
PKGREVISION=	4
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

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${_DISTDIR}/*.ttf ${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
