# $NetBSD: Makefile,v 1.24 2022/08/11 05:08:25 gutteridge Exp $

DISTNAME=	easyrpg-player-0.7.0
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	https://easyrpg.org/downloads/player/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://easyrpg.org/
COMMENT=	RPG Maker 2000/2003 and EasyRPG games interpreter
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES+=	c c++

# "We require now the C++ language standard C++14.
# The lowest GCC compiler supporting this fully is GCC5"
GCC_REQD+=	5

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

# Alternative MIDI implementations
CONFIGURE_ARGS+=	--without-fluidlite
CONFIGURE_ARGS+=	--without-libwildmidi

.include "options.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libxmp/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../games/liblcf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
