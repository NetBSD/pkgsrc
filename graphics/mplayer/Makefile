# $NetBSD: Makefile,v 1.44 2003/12/08 19:20:49 wiz Exp $
#

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}
COMMENT=	Software-only MPEG-1/2/4 video decoder

.include "../../graphics/mplayer-share/Makefile.common"

USE_BUILDLINK2=		# defined
CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../graphics/mplayer-share/Makefile.depends"

.include "../../mk/bsd.pkg.mk"

.include "../../graphics/mplayer-share/Makefile.cflags"
