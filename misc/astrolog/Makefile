# $NetBSD: Makefile,v 1.43 2020/05/03 15:08:29 rillig Exp $

DISTNAME=	ast54unx
PKGNAME=	astrolog-5.40
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.astrolog.org/ftp/ephem/
MASTER_SITES+=	http://www.astrolog.org/ftp/
DISTFILES=	${DISTNAME}.shr ${EPHEM}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.astrolog.org/
COMMENT=	Astrology program for X11 and alpha-numeric terminals
LICENSE=	astrolog-license

RESTRICTED=		Do not sell or profit from this software in any way
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}
EPHEM=		LRZ5_24 CHI_24 CPJV_24
EXTRACT_ONLY=	${DISTNAME}.shr

DIST_SUBDIR=	astrolog
BUILD_TARGET=	astrolog

# 1 in xscreen.c, 1 in charts.c, both harmless.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INSTALLATION_DIRS=	bin

do-install:
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/astrolog
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		${INSTALL_DATA} ${EPHEM} ${DESTDIR}${PREFIX}/lib/astrolog
	cd ${WRKSRC} && \
		if [ -f ${DESTDIR}${PREFIX}/lib/astrolog/astrolog.dat ] ; then \
			${INSTALL_DATA} astrolog.dat ${DESTDIR}${PREFIX}/lib/astrolog/astrolog.dat-dist; \
		else \
			${INSTALL_DATA} astrolog.dat ${DESTDIR}${PREFIX}/lib/astrolog; \
		fi
	cd ${WRKSRC} && ${INSTALL_PROGRAM} astrolog ${DESTDIR}${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Helpfile.540 ${DESTDIR}${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Update.540 ${DESTDIR}${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.540 ${DESTDIR}${PREFIX}/share/doc/astrolog
	@${ECHO}
	@${ECHO} "See the file ${PREFIX}/share/doc/astrolog/Helpfile.540 for"
	@${ECHO} "help and tune ${PREFIX}/lib/astrolog/astrolog.dat"

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
