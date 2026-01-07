# $NetBSD: Makefile,v 1.53 2026/01/07 08:48:22 wiz Exp $

DISTNAME=		LibVNCServer-0.9.15
PKGNAME=		libVNCServer-0.9.15
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=LibVNC/}
GITHUB_PROJECT=		libvncserver
GITHUB_TAG=		LibVNCServer-${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://libvnc.github.io/
COMMENT=		Easy API to write one's own vnc server
LICENSE=		gnu-gpl-v2

# XXX doesn't really use c++ but cmake is being uncooperative
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	src/libvncserver/libvncserver.pc.cmakein
PKGCONFIG_OVERRIDE+=	src/libvncserver/libvncclient.pc.cmakein

CMAKE_CONFIGURE_ARGS+=		-DWITH_FFMPEG=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_GTK=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_QT=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_SDL=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_SYSTEMD=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_EXAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_THREADS=ON
CMAKE_CONFIGURE_ARGS+=		-DWITH_TIGHTVNC_FILETRANSFER=ON
CMAKE_CONFIGURE_ARGS+=		-DWITH_WEBSOCKETS=ON
CMAKE_CONFIGURE_ARGS+=		-DWITH_24BPP=ON
CMAKE_CONFIGURE_ARGS+=		-DWITH_LZO=ON
CMAKE_CONFIGURE_ARGS+=		-DWITH_ZLIB=ON
CMAKE_CONFIGURE_ARGS+=		-DWITH_JPEG=ON
CMAKE_CONFIGURE_ARGS+=		-DWITH_PNG=ON
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_POLICY_VERSION_MINIMUM=3.5

LDFLAGS.SunOS+=		-lsocket

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
