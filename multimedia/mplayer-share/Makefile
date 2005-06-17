# $NetBSD: Makefile,v 1.3 2005/06/17 03:50:23 jlam Exp $

.include "Makefile.common"

PKGNAME=	mplayer-share-${MPLAYER_PKG_VERSION}
PKGREVISION=	1
COMMENT=	Documentation and fonts used by mplayer and gmplayer

NO_BUILD=	YES
NO_CONFIGURE=	YES

MP_FONTS=	font-arial-iso-8859-1.tar.bz2 \
		font-arial-iso-8859-2.tar.bz2 \
		font-arial-cp1250.tar.bz2
FONT_DIRS=	font-arial-cp1250 font-arial-iso-8859-1 font-arial-iso-8859-2

.for font in ${MP_FONTS}
SITES_${font}=	http://www2.mplayerhq.hu/MPlayer/releases/fonts/ \
		ftp://ftp.mplayerhq.hu/MPlayer/releases/fonts/
.endfor

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${MP_FONTS}

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	man/man1

do-install:
	${INSTALL_MAN} ${WRKSRC}/DOCS/man/en/mplayer.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/DOCS
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/fonts
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/input.conf ${PREFIX}/share/mplayer
	(cd ${WRKSRC}/DOCS && \
		${PAX} -rwpppm * ${PREFIX}/share/mplayer/DOCS); \
	${FIND} ${PREFIX}/share/mplayer/DOCS -type d -exec ${CHMOD} \
     		${PKGDIRMODE} \{\} \;
	${FIND} ${PREFIX}/share/mplayer/DOCS -type f -exec ${CHMOD} \
  		${SHAREMODE} \{\} \;
	for D in ${FONT_DIRS}; do \
		(cd ${WRKDIR}/$$D && \
			${PAX} -rwpppm * ${PREFIX}/share/mplayer/fonts); \
	done
	${LN} -s ${PREFIX}/share/mplayer/fonts/font-arial-18-iso-8859-1 \
		${PREFIX}/share/mplayer/font

.include "../../mk/bsd.pkg.mk"
