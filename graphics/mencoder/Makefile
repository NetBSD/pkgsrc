# $NetBSD: Makefile,v 1.18 2003/10/26 22:51:34 kristerw Exp $
#

PKGNAME=	mencoder-${MPLAYER_PKG_VERSION}
PKGREVISION=	1
COMMENT=	Simple movie encoder for MPlayer-playable movies

.include "../../graphics/mplayer-share/Makefile.common"

USE_BUILDLINK2=		# defined
CONFIGURE_ARGS+=	--disable-nas
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

ALL_TARGET=	mencoder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${PREFIX}/bin
	${LN} -s ${PREFIX}/man/man1/mplayer.1 ${PREFIX}/man/man1/mencoder.1

.include "../../graphics/mplayer-share/Makefile.depends"

.include "../../audio/lame/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
.include "../../graphics/mplayer-share/Makefile.cflags"
