# $NetBSD: Makefile,v 1.31 2019/07/01 04:08:25 ryoon Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	1
COMMENT=	SDL (Simple DirectMedia Layer) bindings for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VIDEO_SDL=True
CMAKE_ARGS+=	-DSDL_INCLUDE_DIR=${PREFIX}/include/SDL

.include	"../../devel/SDL/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
