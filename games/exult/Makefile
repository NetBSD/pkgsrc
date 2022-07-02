# $NetBSD: Makefile,v 1.33 2022/07/02 16:53:16 ryoon Exp $

DISTNAME=	exult-1.6
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=exult/exult-all-versions/}

MAINTAINER=	nikkohigashi@gmail.com
HOMEPAGE=	http://exult.sourceforge.net/
COMMENT=	Open-source Ultima 7 engine
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config yacc flex

# C++17
GCC_REQD+=	7

CONFIGURE_ARGS+=	--with-sdl=sdl2
CONFIGURE_ARGS+=	--disable-timidity-midi
CONFIGURE_ARGS+=	--disable-alsa

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
