# $NetBSD: Makefile,v 1.55 2024/05/16 06:14:57 wiz Exp $

DISTNAME=	SuperTuxKart-1.4-src
PKGNAME=	${DISTNAME:tl:S/-src//}
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=supertuxkart/}
GITHUB_PROJECT=	stk-code
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://supertuxkart.net/Main_Page
COMMENT=	Free 3D kart racing game
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake pkg-config

CMAKE_ARGS+=	-DUSE_WIIUSE=OFF
CMAKE_ARGS+=	-DBUILD_RECORDER=OFF

# "error: sorry, unimplemented: non-trivial designated initializers not supported"
# apparently gcc 8 should work.
USE_CXX_FEATURES+=	c++20

# Needs linux joystick support.
CMAKE_ARGS+=	-DENABLE_WAYLAND_DEVICE=OFF

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
# SDL2 is for GamePad support.
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
