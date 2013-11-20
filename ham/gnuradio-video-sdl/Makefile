# $NetBSD: Makefile,v 1.13 2013/11/20 20:04:38 adam Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	9
COMMENT=	SDL bindings for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-video-sdl
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

PYTHON_PATCH_SCRIPTS+=	gr-video-sdl/src/qa_video_sdl.py

.include "../../devel/SDL/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
