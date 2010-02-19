# $NetBSD: Makefile,v 1.14 2010/02/19 22:04:25 joerg Exp $

DISTNAME=	xev111
PKGNAME=	xbat-1.11
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.nemoto.ecei.tohoku.ac.jp/~wai/Xbat/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nemoto.ecei.tohoku.ac.jp/~wai/index_e.html
COMMENT=	XEVIOUS like shooting game

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=	Possible copyright infringement
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=		${WRKDIR}/Xev111
USE_IMAKE=	yes
BUILD_TARGET=	xbat

MAKE_FLAGS+=	INSTLINFLAGS="-o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE}"
MAKE_FLAGS+=	INSTPGMFLAGS="-o ${GAMEOWN} -g ${GAMEGRP} -m ${GAMEMODE}"
MAKE_FLAGS+=	VARBASE=${VARBASE}

SCORE_DIR=	share/games/Xbat/Score

SETGIDGAME=		yes
SPECIAL_PERMS=		bin/xbat ${SETGID_GAMES_PERMS}
REQD_DIRS_PERMS+=	${VARBASE}/games/Xbat ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
.for n in 0 1 2 3 4
REQD_FILES_PERMS+=	${SCORE_DIR}/top10-${n}.txt			\
			${VARBASE}/games/Xbat/top10-${n}.txt 		\
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
.endfor

BUILD_DEFS+=	VARBASE
BUILD_DEFS+=	GAMEDATAMODE
BUILD_DEFS+=	GAMEMODE

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=	UNION=0
.elif ${MACHINE_ENDIAN} == "little"
MAKE_FLAGS+=	UNION=1
.else
BROKEN=	Unknown endianness
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${SCORE_DIR}
.for n in 0 1 2 3 4
	${INSTALL_DATA} ${WRKSRC}/Score/top10-${n}.txt	\
		${DESTDIR}${PREFIX}/${SCORE_DIR}/top10-${n}.txt
.endfor

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
