# $NetBSD: Makefile,v 1.2 2002/08/07 12:53:06 veego Exp $

.include "Makefile.common"

PKGNAME=	mplayer-share-${MPLAYER_PKG_VERSION}
COMMENT=	Documentation and fonts used by mplayer and gmplayer

MASTER_SITES+=	http://www2.mplayerhq.hu/MPlayer/contrib/fonts/ \
		ftp://ftp2.mplayerhq.hu/MPlayer/contrib/fonts/

NO_BUILD=	YES
NO_CONFIGURE=	YES
NO_PATCH=	YES

MP_FONTS=	mp-arial-iso-8859-1.zip \
		mp-arial-iso-8859-2.zip \
		koi8r-font.tar.bz2

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${MP_FONTS}

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

.include "../../mk/bsd.prefs.mk"

do-install:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${INSTALL_MAN} ${WRKSRC}/DOCS/mplayer.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/font
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/input.conf ${PREFIX}/share/mplayer
	${CP} -R ${WRKSRC}/DOCS ${PREFIX}/share/mplayer
	@${ECHO_MSG} "Installing font ${MPLAYER_FONT}..."
	(cd ${WRKDIR}/${MPLAYER_FONT}; ${PAX} -rwpp . ${PREFIX}/share/mplayer/font)
	(cd ${PREFIX}; ${FIND} share/mplayer/font -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d share/mplayer -type d -print | \
		${SED} -e "s/^/@dirrm /" | ${SORT} -r >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
