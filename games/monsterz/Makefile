# $NetBSD: Makefile,v 1.31 2025/05/17 14:28:55 wiz Exp $

DISTNAME=		monsterz-0.9
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=0-wiz-0/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/0-wiz-0/monsterz
COMMENT=		Puzzle game similar to the famous Bejeweled or Zookeeper
LICENSE=		public-domain AND gnu-gpl-v2 AND gnu-lgpl-v2.1

DEPENDS+=		${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game

REPLACE_PYTHON=		monsterz.py

MAKE_FLAGS+=		prefix=${PREFIX}
MAKE_FLAGS+=		gamesdir=${PREFIX}/bin
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
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
