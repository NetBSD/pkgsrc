# $NetBSD: Makefile,v 1.10 2013/12/31 15:41:17 rodent Exp $

VERSION=	1.1.1
DISTNAME=	solarus-${VERSION}-src
PKGNAME=	${DISTNAME:S/-src//1}
CATEGORIES=	games
MASTER_SITES=	http://www.solarus-games.org/downloads/solarus/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.solarus-games.org/solarus/
COMMENT=	Open-source Zelda-like 2D game engine licensed under GPL
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/solarus-${VERSION}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.fast.prefs.mk"

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/physfs/buildlink3.mk"
LUA_VERSIONS_ACCEPTED=		51
BUILDLINK_API_DEPENDS.lua51+=	lua51>=5.1.5
.include "../../lang/lua/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
