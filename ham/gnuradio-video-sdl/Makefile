# $NetBSD: Makefile,v 1.72 2023/11/12 13:22:23 wiz Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	2
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
