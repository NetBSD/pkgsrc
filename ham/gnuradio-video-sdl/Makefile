# $NetBSD: Makefile,v 1.2 2008/07/14 12:56:06 joerg Exp $

PKGNAME=	gnuradio-video-sdl-${VERSION}
COMMENT=	SDL bindings for GNU Radio

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-video-sdl

PYTHON_PATCH_SCRIPTS+=	gr-video-sdl/src/qa_video_sdl.py

.include "../../devel/SDL/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
