# $NetBSD: Makefile,v 1.3 2003/03/29 12:40:56 jmmv Exp $
#

DISTNAME=	geoslab703-ttf-20010522
WRKSRC=		${WRKDIR}
CATEGORIES=	fonts
MASTER_SITES=	http://www.will-harris.com/fonts/
DISTFILES=	geo703l.ttf geo703li.ttf

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.will-harris.com/fonts/freefonts.htm
COMMENT=	Free TrueType fonts from Bitstream, useful for web viewing

DIST_SUBDIR=	geoslab703-ttf

EXTRACT_ONLY=	# empty
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
