# $NetBSD: Makefile,v 1.13 2004/10/03 00:13:03 tv Exp $
#

PKGNAME=	mencoder-${MPLAYER_PKG_VERSION}
PKGREVISION=	2

COMMENT=	Simple movie encoder for MPlayer-playable movies

.include "../../multimedia/mplayer-share/Makefile.common"

USE_BUILDLINK3=		YES
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

ALL_TARGET=	mencoder

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
