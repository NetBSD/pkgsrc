# $NetBSD: Makefile,v 1.30 2024/12/14 17:11:08 wiz Exp $

DISTNAME=		monsterz-0.8
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=0-wiz-0/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/0-wiz-0/monsterz
COMMENT=		Puzzle game similar to the famous Bejeweled or Zookeeper
# closest match
LICENSE=		public-domain

DEPENDS+=		${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game

REPLACE_PYTHON=			monsterz.py

MAKE_FLAGS+=		prefix=${PREFIX}
MAKE_FLAGS+=		gamesdir=${PREFIX}/bin
MAKE_FLAGS+=		scoredir=${VARBASE}/games
MAKE_ENV+=		GAMEOWN=${GAMES_USER:Q}
MAKE_ENV+=		GAMEGRP=${GAMES_GROUP:Q}
MAKE_ENV+=		VARBASE=${VARBASE}

USE_GAMESGROUP=		yes
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/monsterz \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS=		bin/monsterz ${SETGID_GAMES_PERMS}

BUILD_DEFS+=		VARBASE

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
