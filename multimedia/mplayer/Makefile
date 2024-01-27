# $NetBSD: Makefile,v 1.113 2024/01/27 02:11:04 riastradh Exp $

PKGNAME=	mplayer-${MPLAYER_VERSION}
PKGREVISION=	3

COMMENT=	Fast, cross-platform movie player

.include "../../multimedia/mplayer-share/Makefile.common"

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-xvmc
CONFIGURE_ARGS+=	--with-xvmclib=XvMCW

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
CONFIGURE_ARGS+=	--target=${MACHINE_ARCH:Q}-${OPSYS:Q}
# Reaching into the destdir with a -I flag to NATIVE_CC is kinda
# sleazy, but this will probably work and it saves the trouble of
# pulling in a gigantic tool dependency.
CONFIGURE_ARGS+=	--host-cc=${NATIVE_CC:Q}\ -I${_CROSS_DESTDIR:Q}${LOCALBASE:Q}/include/ffmpeg5
#TOOL_DEPENDS+=		ffmpeg5>=0:../../multimedia/ffmpeg5
#CONFIGURE_ARGS+=	--host-cc=${NATIVE_CC:Q}\ -I${TOOLBASE:Q}/include/ffmpeg5
.else
CONFIGURE_ARGS+=	--host-cc=${CC:Q}\ ${BUILDLINK_CPPFLAGS:Q}
.endif

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
