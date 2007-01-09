# $NetBSD: Makefile,v 1.31 2007/01/09 14:49:33 drochner Exp $

PKGNAME=	mencoder-${MPLAYER_PKG_VERSION}

PKGREVISION=	2

COMMENT=	Simple movie encoder for MPlayer-playable movies

.include "../../multimedia/mplayer-share/Makefile.common"

CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

BUILD_TARGET=	mencoder

MANCOMPRESSED_IF_MANZ=	1
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${PREFIX}/bin
	if [ X"${MANZ}" = X"" ]; then \
		${LN} -s -f ${PREFIX}/${PKGMANDIR}/man1/mplayer.1 \
			${PREFIX}/${PKGMANDIR}/man1/mencoder.1; \
	else \
		${LN} -s -f ${PREFIX}/${PKGMANDIR}/man1/mplayer.1.gz \
			${PREFIX}/${PKGMANDIR}/man1/mencoder.1.gz; \
	fi

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
