# $NetBSD: Makefile,v 1.15 2007/12/17 20:49:34 tron Exp $
#

DISTNAME=	libtheora-1.0beta2
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/theora/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.theora.org/
COMMENT=	Video codec for Ogg multimedia streaming

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	theora.pc.in
USE_LIBTOOL=		YES
TEST_TARGET=		check

CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	HAVE_DOXYGEN=false
# disable player
CONFIGURE_ENV+=		ac_cv_path_SDL_CONFIG=no

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-[9].*-i386)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
