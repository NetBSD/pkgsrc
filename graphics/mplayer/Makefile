# $NetBSD: Makefile,v 1.35 2003/05/25 07:20:52 dan Exp $
#

.include "../../graphics/mplayer-share/Makefile.common"

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}
PKGREVISION=	3
COMMENT=	Software only MPEG-1/2/4 video decoder

USE_BUILDLINK2=		# defined
CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../graphics/mplayer-share/Makefile.depends"

.include "../../audio/nas/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

.include "../../graphics/mplayer-share/Makefile.cflags"
