# $NetBSD: Makefile,v 1.111 2023/11/23 17:21:51 tsutsui Exp $

PKGNAME=	mplayer-${MPLAYER_VERSION}
PKGREVISION=	2

COMMENT=	Fast, cross-platform movie player

.include "../../multimedia/mplayer-share/Makefile.common"

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer
CONFIGURE_ARGS+=	--enable-xvmc
CONFIGURE_ARGS+=	--with-xvmclib=XvMCW

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${DESTDIR}${PREFIX}/bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/mplayer-share/depends.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
