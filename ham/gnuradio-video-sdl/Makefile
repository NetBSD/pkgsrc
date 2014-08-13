# $NetBSD: Makefile,v 1.15 2014/08/13 10:57:36 adam Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	10
COMMENT=	SDL bindings for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-video-sdl
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

REPLACE_PYTHON+=	gr-video-sdl/src/qa_video_sdl.py

.include "../../devel/SDL/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
