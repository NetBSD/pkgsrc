# $NetBSD: Makefile,v 1.8 1998/08/20 15:17:12 tsarna Exp $
# FreeBSD Id: Makefile,v 1.12 1997/08/10 22:31:15 fenner Exp
#

DISTNAME=       ast53unx
PKGNAME=        astrolog-5.30
CATEGORIES=     misc
MASTER_SITES=   http://www.astrolog.org/ftp/ephem/ \
		http://www.astrolog.org/ftp/ \
		ftp://ftp.kiarchive.ru/pub/unix/magick/astrology/astrolog/
DISTFILES=      ${EXTRACT_ONLY} ${EPHEM}

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.astrolog.org/

EPHEM=          LRZ5_24 CHI_24 CPJV_24

USE_X11=	yes

EXTRACT_ONLY=   ${DISTNAME}.shr
EXTRACT_CMD=    ${SH}
EXTRACT_ARGS=
DIST_SUBDIR=    astrolog
ALL_TARGET=     astrolog
NO_WRKSUBDIR=   yes

do-install:
	-@${MKDIR} ${PREFIX}/lib/astrolog
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		${INSTALL_DATA} ${EPHEM} ${PREFIX}/lib/astrolog
	cd ${WRKSRC} && \
		if [ -f ${PREFIX}/lib/astrolog/astrolog.dat ] ; then \
			${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog/astrolog.dat-dist; \
		else \
			${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog; \
		fi
	cd ${WRKSRC} && ${INSTALL_PROGRAM} astrolog ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Helpfile.530 ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Update.530 ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.530 ${PREFIX}/share/doc/astrolog
	@${ECHO}
	@${ECHO} "See the file ${PREFIX}/share/doc/astrolog/Helpfile.530 for"
	@${ECHO} "help and tune ${PREFIX}/lib/astrolog/astrolog.dat"

.include "../../mk/bsd.pkg.mk"
