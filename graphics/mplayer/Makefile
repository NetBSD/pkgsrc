# $NetBSD: Makefile,v 1.26 2002/06/08 23:41:56 veego Exp $

.include "../../graphics/mplayer-share/Makefile.common"

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}
COMMENT=	Software only MPEG-1/2/4 video decoder

CONFIGURE_ARGS+=	--disable-mencoder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../audio/nas/buildlink.mk"
.include "../../graphics/mplayer-share/Makefile.depends"
.include "../../mk/bsd.pkg.mk"
