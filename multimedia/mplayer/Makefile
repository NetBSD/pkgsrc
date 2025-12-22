# $NetBSD: Makefile,v 1.120 2025/12/22 06:08:14 adam Exp $

PKGNAME=	mplayer-${MPLAYER_VERSION}
PKGREVISION=	1

COMMENT=	Fast, cross-platform movie player

.include "../../multimedia/mplayer-share/Makefile.common"

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--disable-gif # giflib removes private API

INSTALLATION_DIRS+=	bin

LDFLAGS.SunOS+=	-lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${DESTDIR}${PREFIX}/bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/mplayer-share/depends.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
#.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
