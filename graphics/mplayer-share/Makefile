# $NetBSD: Makefile,v 1.3 2002/12/06 14:21:46 wiz Exp $

.include "Makefile.common"

PKGNAME=	mplayer-share-${MPLAYER_PKG_VERSION}
COMMENT=	Documentation and fonts used by mplayer and gmplayer
# XXX: Remove following line during next update!
PKGREVISION=	1

NO_BUILD=	YES
NO_CONFIGURE=	YES
NO_PATCH=	YES

MP_FONTS=	font-arial-iso-8859-1.tar.bz2 \
		font-arial-iso-8859-2.tar.bz2 \
		font-arial-cp1250.tar.bz2
FONT_FILES=	README-arial-iso-8859-1 README-arial-iso-8859-2 cp1250 \
		font-arial-14-iso-8859-1 font-arial-14-iso-8859-2 \
		font-arial-18-iso-8859-1 font-arial-18-iso-8859-2 \
		font-arial-24-iso-8859-1 font-arial-24-iso-8859-2 \
		font-arial-28-iso-8859-1 font-arial-28-iso-8859-2

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
	cd ${WRKDIR}; ${PAX} -rw ${FONT_FILES} ${PREFIX}/share/mplayer/fonts

.include "../../mk/bsd.pkg.mk"
