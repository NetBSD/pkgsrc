# $NetBSD: Makefile,v 1.21 2003/12/12 22:09:02 wiz Exp $
#

PKGNAME=	mencoder-${MPLAYER_PKG_VERSION}
COMMENT=	Simple movie encoder for MPlayer-playable movies

.include "../../graphics/mplayer-share/Makefile.common"

USE_BUILDLINK2=		# defined
CONFIGURE_ARGS+=	--disable-nas
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

.include "../../graphics/mplayer-share/Makefile.depends"

.include "../../audio/lame/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
.include "../../graphics/mplayer-share/Makefile.cflags"
