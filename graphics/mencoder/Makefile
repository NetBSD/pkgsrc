# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 18:46:37 jlam Exp $

.include "../../graphics/mplayer-share/Makefile.common"

PKGNAME=	mencoder-${MPLAYER_PKG_VERSION}
COMMENT=	Simple movie encoder for MPlayer-playable movies

CONFIGURE_ARGS+= --disable-nas

ALL_TARGET=	mencoder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${PREFIX}/bin
	${LN} -s ${PREFIX}/man/man1/mplayer.1   ${PREFIX}/man/man1/mencoder.1

.include "../../audio/lame/buildlink.mk"
.include "../../graphics/mplayer-share/Makefile.depends"
.include "../../mk/bsd.pkg.mk"
