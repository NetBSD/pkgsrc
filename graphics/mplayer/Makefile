# $NetBSD: Makefile,v 1.25 2002/05/25 07:56:02 veego Exp $

.include "../../graphics/mplayer-share/Makefile.common"

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}
COMMENT=	Software only MPEG-1/2/4 video decoder

DEPENDS+=	mplayer-share>=0.90rc4nb1:../../graphics/mplayer-share

CONFIGURE_ARGS+=	--disable-mencoder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../devel/SDL/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../misc/libdvdread/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
