# $NetBSD: Makefile,v 1.10 2003/07/20 20:15:02 dillo Exp $

.include "Makefile.common"

PKGNAME=	mplayer-share-${MPLAYER_PKG_VERSION}
PKGREVISION=	4
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

do-install:
	${INSTALL_MAN} ${WRKSRC}/DOCS/mplayer.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/fonts
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/input.conf ${PREFIX}/share/mplayer
	${CP} -R ${WRKSRC}/DOCS ${PREFIX}/share/mplayer
	for D in ${FONT_DIRS}; do \
		(cd ${WRKDIR}/$$D && \
			${PAX} -rw * ${PREFIX}/share/mplayer/fonts); \
	done
	${LN} -s ${PREFIX}/share/mplayer/fonts/font-arial-18-iso-8859-1 \
		${PREFIX}/share/mplayer/font

.include "../../mk/bsd.pkg.mk"
