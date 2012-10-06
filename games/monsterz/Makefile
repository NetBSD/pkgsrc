# $NetBSD: Makefile,v 1.10 2012/10/06 11:54:47 asau Exp $
#

DISTNAME=		monsterz-0.7.1
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		http://sam.zoy.org/monsterz/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/monsterz/
COMMENT=		Puzzle game similar to the famous Bejeweled or Zookeeper

DEPENDS+=		${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=		${PYPKGPREFIX}-Numeric-[0-9]*:../../math/py-Numeric

PYTHON_PATCH_SCRIPTS=	monsterz.py

MAKE_ENV+=		GAMEOWN=${GAMEOWN:Q}
MAKE_ENV+=		GAMEGRP=${GAMEGRP:Q}
MAKE_ENV+=		VARBASE=${VARBASE:Q}

SETGIDGAME=		yes
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/monsterz \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS=		bin/monsterz ${SETGID_GAMES_PERMS}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
