# $NetBSD: Makefile,v 1.16 2017/08/01 14:58:59 wiz Exp $
#

DISTNAME=		dd2-0.2.2
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		https://www.usebox.net/jjm/dd2/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.usebox.net/jjm/dd2/
COMMENT=		Shoot'em up arcade game for one or two players

GNU_CONFIGURE=		yes

DD2_SCORE=		${VARBASE}/games
CFLAGS+=		-DDD2_SCORE=\"${DD2_SCORE}\"

SETGIDGAME=		yes
SPECIAL_PERMS=		bin/dd2 ${SETGID_GAMES_PERMS}
REQD_DIRS_PERMS+=	${DD2_SCORE} ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
REQD_FILES_PERMS+=	share/dd2/dd2-hiscore ${DD2_SCORE}/dd2-hiscore	\
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE
BUILD_DEFS+=		GAMEMODE

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
