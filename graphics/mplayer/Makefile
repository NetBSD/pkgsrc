# $NetBSD: Makefile,v 1.24.2.1 2002/06/23 18:46:41 jlam Exp $

.include "../../graphics/mplayer-share/Makefile.common"

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}
COMMENT=	Software only MPEG-1/2/4 video decoder

CONFIGURE_ARGS+=	--disable-mencoder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../audio/nas/buildlink.mk"
.include "../../graphics/mplayer-share/Makefile.depends"
.include "../../mk/bsd.pkg.mk"
