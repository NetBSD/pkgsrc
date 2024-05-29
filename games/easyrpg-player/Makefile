# $NetBSD: Makefile,v 1.38 2024/05/29 16:32:33 adam Exp $

DISTNAME=	easyrpg-player-0.7.0
PKGREVISION=	16
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

BROKEN+=	"Incompatible with latest fmtlib"

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
