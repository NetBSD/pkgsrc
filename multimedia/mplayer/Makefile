# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 12:08:12 jmmv Exp $

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}
PKGREVISION=	1
COMMENT=	Software-only MPEG-1/2/4 video decoder

.include "../../multimedia/mplayer-share/Makefile.common"

USE_BUILDLINK2=		# defined
CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../mk/bsd.pkg.mk"

.include "../../multimedia/mplayer-share/Makefile.cflags"
