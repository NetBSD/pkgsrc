# $NetBSD: Makefile,v 1.1.1.1 2002/08/05 13:29:13 veego Exp $
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
NO_PATCH=	yes
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
