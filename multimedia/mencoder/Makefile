# $NetBSD: Makefile,v 1.16 2004/12/17 22:33:13 tron Exp $

PKGNAME=	mencoder-${MPLAYER_PKG_VERSION}

COMMENT=	Simple movie encoder for MPlayer-playable movies

.include "../../multimedia/mplayer-share/Makefile.common"

USE_BUILDLINK3=		YES
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

BUILD_TARGET=	mencoder

MANCOMPRESSED_IF_MANZ=	1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${PREFIX}/bin
	if [ X"${MANZ}" = X"" ]; then \
		${LN} -s -f ${PREFIX}/man/man1/mplayer.1 \
			${PREFIX}/man/man1/mencoder.1; \
	else \
		${LN} -s -f ${PREFIX}/man/man1/mplayer.1.gz \
			${PREFIX}/man/man1/mencoder.1.gz; \
	fi

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../audio/lame/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
