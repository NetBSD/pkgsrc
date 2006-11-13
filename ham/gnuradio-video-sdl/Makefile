# $NetBSD: Makefile,v 1.1.1.1 2006/11/13 17:36:32 wulf Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
COMMENT=	SDL bindings for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-video-sdl

PYTHON_PATCH_SCRIPTS+=	gr-video-sdl/src/qa_video_sdl.py

.include "../../devel/SDL/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
