# $NetBSD: Makefile,v 1.2 2003/03/28 21:14:19 wiz Exp $
#

DISTNAME=	geoslab703-ttf-20010522
CATEGORIES=	fonts
MASTER_SITES=	http://www.will-harris.com/fonts/
DISTFILES=	geo703l.ttf geo703li.ttf

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.will-harris.com/fonts/freefonts.htm
COMMENT=	Free TrueType fonts from Bitstream, useful for web viewing

DIST_SUBDIR=	geoslab703-ttf

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_X11BASE=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR}
	for f in ${DISTFILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${FONTDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
