# $NetBSD: Makefile,v 1.91 2025/02/27 13:49:55 adam Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
COMMENT=	SDL (Simple DirectMedia Layer) bindings for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_VIDEO_SDL=ON
CMAKE_CONFIGURE_ARGS+=	-DSDL_INCLUDE_DIR=${PREFIX}/include/SDL

REPLACE_PYTHON+=	gr-video-sdl/python/video_sdl/*.py

.include "../../devel/sdl12-compat/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
