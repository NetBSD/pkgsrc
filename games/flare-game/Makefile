# $NetBSD: Makefile,v 1.7 2019/07/01 13:20:51 nia Exp $
#

DISTNAME=	flare-game-1.10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=flareteam/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flarerpg.org/
COMMENT=	Fantasy action RPG using the FLARE engine
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0 AND ofl-v1.1 AND gnu-gpl-v2

DEPENDS+=	flare-engine>=1.10:../../games/flare-engine

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

REPLACE_PYTHON+=	mods/alpha_demo/languages/xgettext.py
REPLACE_PYTHON+=	mods/default/languages/xgettext.py
REPLACE_PYTHON+=	mods/fantasycore/languages/xgettext.py

CMAKE_ARGS+=	-DDATADIR:STRING="${PREFIX}/share/flare"

.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
