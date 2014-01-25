# $NetBSD: Makefile,v 1.14 2014/01/25 10:45:19 wiz Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	9
COMMENT=	SDL bindings for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-video-sdl
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

REPLACE_PYTHON+=	gr-video-sdl/src/qa_video_sdl.py

.include "../../devel/SDL/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
