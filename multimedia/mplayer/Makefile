# $NetBSD: Makefile,v 1.13.4.1 2005/04/21 15:20:40 salo Exp $

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}
PKGREVISION=	2

COMMENT=	Software-only MPEG-1/2/4 video decoder

.include "../../multimedia/mplayer-share/Makefile.common"

USE_BUILDLINK3=		YES
CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../mk/bsd.pkg.mk"

.include "../../multimedia/mplayer-share/Makefile.cflags"
