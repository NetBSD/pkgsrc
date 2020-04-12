# $NetBSD: Makefile,v 1.45 2020/04/12 08:28:45 adam Exp $

VERSION=	1.5.1
DISTNAME=	solarus-${VERSION}-src
PKGNAME=	${DISTNAME:S/-src//1}
PKGREVISION=	22
CATEGORIES=	games
MASTER_SITES=	http://www.solarus-games.org/downloads/solarus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.solarus-games.org/solarus/
COMMENT=	Open-source Zelda-like 2D game engine licensed under GPL
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/solarus-${VERSION}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

GCC_REQD+=	4.8
LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
LUA_VERSIONS_ACCEPTED=		51
BUILDLINK_API_DEPENDS.lua51+=	lua51>=5.1.5
.include "../../lang/lua/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2_ttf+=	SDL2_ttf>=2.0.12
.include "../../fonts/SDL2_ttf/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2_image+=	SDL2_image>=2.0.0
.include "../../graphics/SDL2_image/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2+=	SDL2>=2.0.1
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
