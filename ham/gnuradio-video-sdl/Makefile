# $NetBSD: Makefile,v 1.10 2012/10/03 13:01:44 asau Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	6
COMMENT=	SDL bindings for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-video-sdl
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

PYTHON_PATCH_SCRIPTS+=	gr-video-sdl/src/qa_video_sdl.py

.include "../../devel/SDL/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
