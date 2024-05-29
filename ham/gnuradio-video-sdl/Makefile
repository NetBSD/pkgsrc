# $NetBSD: Makefile,v 1.78 2024/05/29 16:33:07 adam Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	3
COMMENT=	SDL (Simple DirectMedia Layer) bindings for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_VIDEO_SDL=ON
CMAKE_ARGS+=	-DSDL_INCLUDE_DIR=${PREFIX}/include/SDL
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
