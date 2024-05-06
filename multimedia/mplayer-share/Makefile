# $NetBSD: Makefile,v 1.95 2024/05/06 08:40:29 jperkin Exp $

PKGREVISION= 14
.include "Makefile.common"

PKGNAME=	mplayer-share-${MPLAYER_VERSION}
COMMENT=	Documentation used by mplayer and gmplayer

DEPENDS+=	mplayer-fonts-[0-9]*:../../fonts/mplayer-fonts

USE_TOOLS+=	pax

NO_BUILD=	YES
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/mplayer/DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/DOCS/man/en/mplayer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${DESTDIR}${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/input.conf ${DESTDIR}${PREFIX}/share/mplayer
	(set -e; cd ${WRKSRC}/DOCS && \
		pax -rwppm * ${DESTDIR}${PREFIX}/share/mplayer/DOCS); \
	${FIND} ${DESTDIR}${PREFIX}/share/mplayer/DOCS -type d -print | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${PREFIX}/share/mplayer/DOCS -type f -print | \
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
