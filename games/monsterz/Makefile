# $NetBSD: Makefile,v 1.23 2019/09/02 13:20:20 adam Exp $

DISTNAME=		monsterz-0.7.1
PKGREVISION=		5
CATEGORIES=		games
MASTER_SITES=		http://sam.zoy.org/monsterz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/monsterz/
COMMENT=		Puzzle game similar to the famous Bejeweled or Zookeeper

DEPENDS+=		${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=		${PYPKGPREFIX}-Numeric-[0-9]*:../../math/py-Numeric

REPLACE_PYTHON=			monsterz.py
PYTHON_VERSIONS_ACCEPTED=	 27 # py-Numeric

MAKE_ENV+=		GAMEOWN=${GAMEOWN:Q}
MAKE_ENV+=		GAMEGRP=${GAMEGRP:Q}
MAKE_ENV+=		VARBASE=${VARBASE}

SETGIDGAME=		yes
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/monsterz \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS=		bin/monsterz ${SETGID_GAMES_PERMS}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
