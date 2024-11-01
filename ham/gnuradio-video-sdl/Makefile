# $NetBSD: Makefile,v 1.84 2024/11/01 12:53:06 wiz Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	8
COMMENT=	SDL (Simple DirectMedia Layer) bindings for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_VIDEO_SDL=ON
CMAKE_CONFIGURE_ARGS+=	-DSDL_INCLUDE_DIR=${PREFIX}/include/SDL
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
