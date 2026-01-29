# $NetBSD: Makefile,v 1.8 2026/01/29 16:59:56 ktnb Exp $

.include "../../games/angband/Makefile.common"

PKGNAME=	${DISTNAME:S/angband-/angband-sdl-/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Single-player dungeon exploration game (version with graphics/sound)

CONFLICTS+=	angband-[0-9]*
CONFLICTS+=	angband-tty-[0-9]*
CONFLICTS+=	angband-x11-[0-9]*
SUPERSEDES=	angband-x11-[0-9]*

CONFIGURE_ARGS+=	--enable-sdl2

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
