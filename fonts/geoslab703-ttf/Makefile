# $NetBSD: Makefile,v 1.15 2015/07/04 16:18:31 joerg Exp $
#

DISTNAME=	geoslab703-ttf-20010522
PKGREVISION=	5
CATEGORIES=	fonts
MASTER_SITES=	http://www.will-harris.com/fonts/
DISTFILES=	geo703l.ttf geo703li.ttf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.will-harris.com/fonts/freefonts.htm
COMMENT=	Free TrueType fonts from Bitstream, useful for web viewing

DIST_SUBDIR=	geoslab703-ttf
EXTRACT_ONLY=	# empty

NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${_DISTDIR}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
