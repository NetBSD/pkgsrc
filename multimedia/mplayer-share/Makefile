# $NetBSD: Makefile,v 1.10 2006/06/13 17:25:00 drochner Exp $

.include "Makefile.common"

PKGNAME=	mplayer-share-${MPLAYER_PKG_VERSION}
COMMENT=	Documentation used by mplayer and gmplayer

DEPENDS+=	mplayer-fonts-[0-9]*:../../fonts/mplayer-fonts

NO_BUILD=	YES
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	man/man1

do-install:
	${INSTALL_MAN} ${WRKSRC}/DOCS/man/en/mplayer.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/DOCS
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/input.conf ${PREFIX}/share/mplayer
	(cd ${WRKSRC}/DOCS && \
		${PAX} -rwpppm * ${PREFIX}/share/mplayer/DOCS); \
	${FIND} ${PREFIX}/share/mplayer/DOCS -type d -exec ${CHMOD} \
     		${PKGDIRMODE} \{\} \;
	${FIND} ${PREFIX}/share/mplayer/DOCS -type f -exec ${CHMOD} \
		${SHAREMODE} \{\} \;

.include "../../mk/bsd.pkg.mk"
