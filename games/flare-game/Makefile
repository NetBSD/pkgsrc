# $NetBSD: Makefile,v 1.4 2015/04/25 14:22:54 tnn Exp $
#

DISTNAME=	v0.19
PKGNAME=	flare-game-${DISTNAME:S/v//1}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://github.com/clintbellanger/flare-game/archive/
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://flarerpg.org/
COMMENT=	Fantasy action RPG using the FLARE engine
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0 AND ofl-v1.1 AND gnu-gpl-v2

DEPENDS+=	flare-engine>=0.19:../../games/flare-engine

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DDATADIR:STRING="${PREFIX}/share/flare" -DBINDIR:STRING=bin -DMANDIR:STRING=${PKGMANDIR}

REPLACE_PYTHON+=	mods/alpha_demo/languages/xgettext.py
REPLACE_PYTHON+=	mods/default/languages/xgettext.py
REPLACE_PYTHON+=	mods/fantasycore/languages/xgettext.py

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
