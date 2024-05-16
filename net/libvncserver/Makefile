# $NetBSD: Makefile,v 1.43 2024/05/16 06:15:21 wiz Exp $

DISTNAME=		libvncserver-LibVNCServer-0.9.13
PKGNAME=		libVNCServer-0.9.13
PKGREVISION=		9
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
USE_CMAKE=		yes

PKGCONFIG_OVERRIDE+=	libvncserver.pc.cmakein
PKGCONFIG_OVERRIDE+=	libvncclient.pc.cmakein

CMAKE_ARGS+=		-DWITH_FFMPEG=OFF
CMAKE_ARGS+=		-DWITH_GTK=OFF
CMAKE_ARGS+=		-DWITH_SDL=OFF
CMAKE_ARGS+=		-DWITH_SYSTEMD=OFF

CMAKE_ARGS+=		-DWITH_THREADS=ON
CMAKE_ARGS+=		-DWITH_TIGHTVNC_FILETRANSFER=ON
CMAKE_ARGS+=		-DWITH_WEBSOCKETS=ON
CMAKE_ARGS+=		-DWITH_24BPP=ON
CMAKE_ARGS+=		-DWITH_LZO=ON
CMAKE_ARGS+=		-DWITH_ZLIB=ON
CMAKE_ARGS+=		-DWITH_JPEG=ON
CMAKE_ARGS+=		-DWITH_PNG=ON

LDFLAGS.SunOS+=		-lsocket

.include "options.mk"

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
