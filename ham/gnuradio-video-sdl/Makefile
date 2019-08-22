# $NetBSD: Makefile,v 1.32 2019/08/22 12:23:23 ryoon Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	2
COMMENT=	SDL (Simple DirectMedia Layer) bindings for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VIDEO_SDL=True
CMAKE_ARGS+=	-DSDL_INCLUDE_DIR=${PREFIX}/include/SDL

.include	"../../devel/SDL/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
