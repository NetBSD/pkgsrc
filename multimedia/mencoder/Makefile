# $NetBSD: Makefile,v 1.43 2009/02/03 12:01:04 drochner Exp $

PKGNAME=	mencoder-${MPLAYER_PKG_VERSION}
PKGREVISION=	7

COMMENT=	Simple movie encoder for MPlayer-playable movies

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/mplayer-share/Makefile.common"

CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

BUILD_TARGET=	mencoder

MANCOMPRESSED_IF_MANZ=	1
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${DESTDIR}${PREFIX}/bin
	if [ X"${MANZ}" = X"" ]; then \
		${LN} -s -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mplayer.1 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mencoder.1; \
	else \
		${LN} -s -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mplayer.1.gz \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mencoder.1.gz; \
	fi

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
