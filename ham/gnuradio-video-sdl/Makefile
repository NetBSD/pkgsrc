# $NetBSD: Makefile,v 1.5 2012/01/09 02:54:27 obache Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
PKGREVISION=	2
COMMENT=	SDL bindings for GNU Radio

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-video-sdl
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

PYTHON_PATCH_SCRIPTS+=	gr-video-sdl/src/qa_video_sdl.py

.include "../../devel/SDL/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
