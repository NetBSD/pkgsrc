# $NetBSD: Makefile,v 1.27 2005/06/17 03:50:21 jlam Exp $

DISTNAME=       ast54unx
PKGNAME=        astrolog-5.40
CATEGORIES=     misc
MASTER_SITES=   http://www.astrolog.org/ftp/ephem/ \
		http://www.astrolog.org/ftp/ \
		ftp://ftp.kiarchive.ru/pub/unix/magick/astrology/astrolog/
DISTFILES=      ${DISTNAME}.shr ${EPHEM}

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://www.astrolog.org/
COMMENT=	Astrology program for X11 and alpha-numeric terminals

LICENSE=	astrolog-license
RESTRICTED=	Do not sell or profit from this software in any way
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}
EPHEM=          LRZ5_24 CHI_24 CPJV_24
EXTRACT_ONLY=	${DISTNAME}.shr
EXTRACT_CMD=	${EXTRACT_CMD.shar}

USE_X11BASE=	yes

DIST_SUBDIR=    astrolog
BUILD_TARGET=     astrolog

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/astrolog
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		${INSTALL_DATA} ${EPHEM} ${PREFIX}/lib/astrolog
	cd ${WRKSRC} && \
		if [ -f ${PREFIX}/lib/astrolog/astrolog.dat ] ; then \
			${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog/astrolog.dat-dist; \
		else \
			${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog; \
		fi
	cd ${WRKSRC} && ${INSTALL_PROGRAM} astrolog ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Helpfile.540 ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Update.540 ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.540 ${PREFIX}/share/doc/astrolog
	@${ECHO}
	@${ECHO} "See the file ${PREFIX}/share/doc/astrolog/Helpfile.540 for"
	@${ECHO} "help and tune ${PREFIX}/lib/astrolog/astrolog.dat"

.include "../../mk/bsd.pkg.mk"
