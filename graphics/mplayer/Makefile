# $NetBSD: Makefile,v 1.29 2003/01/20 07:10:42 fredb Exp $

.include "../../graphics/mplayer-share/Makefile.common"

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}
COMMENT=	Software only MPEG-1/2/4 video decoder

USE_BUILDLINK2=		# defined
CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../graphics/mplayer-share/Makefile.depends"

.include "../../audio/nas/buildlink2.mk"

.include "../../graphics/mplayer-share/Makefile.cflags"
.include "../../mk/bsd.pkg.mk"
