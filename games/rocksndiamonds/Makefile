# $NetBSD: Makefile,v 1.31 2006/07/22 23:16:42 heinz Exp $

DISTNAME=	rocksndiamonds-3.2.0
CATEGORIES=	games x11
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://www.artsoft.org/rocksndiamonds/
COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	${PKGMANDIR}/man6

PKG_GROUPS+=	${GAMEGRP}
PKG_USERS+=	${GAMEOWN}:${GAMEGRP}

SHARESUBDIR=		share/rocksndiamonds
SHAREDIR=		${PREFIX}/${SHARESUBDIR}

SCORE_PATH=	${VARBASE}/games/rocksndiamonds

REQD_DIRS+=		${SHARESUBDIR}

OWN_DIRS_PERMS+=	${SCORE_PATH:Q}
OWN_DIRS_PERMS+=	${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores
OWN_DIRS_PERMS+=	${GAMEOWN} ${GAMEGRP} 750
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/classic_boulderdash
OWN_DIRS_PERMS+=	${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/classic_emerald_mine
OWN_DIRS_PERMS+=	${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/classic_sokoban
OWN_DIRS_PERMS+=	${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/classic_supaplex
OWN_DIRS_PERMS+=	${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/rnd_tutorial_aaron_davidson
OWN_DIRS_PERMS+=	${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/rnd_tutorial_niko_boehm
OWN_DIRS_PERMS+=	${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}

PLIST_SRC=	PLIST ${WRKDIR}/PLIST.F ${WRKDIR}/PLIST.D

.if ( ${MACHINE} == "i386" || ${MACHINE} == "prep" || ${MACHINE} == "cats" || \
      ${MACHINE} == "shark" )
MAKE_FLAGS+=	JOYSTICK=-DHAVE_JOYSTICK
.endif

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	MAKE=${MAKE_PROGRAM:Q}
MAKE_FLAGS+=	X11_PATH=${X11BASE:Q}
MAKE_FLAGS+=	RO_GAME_DIR=${PREFIX:Q}/share/rocksndiamonds
MAKE_FLAGS+=	RW_GAME_DIR=${SCORE_PATH:Q}
MAKE_FLAGS+=	X11_INCL=
MAKE_FLAGS+=	X11_LIBS=-lX11

.include "options.mk"

do-install:
	${INSTALL_GAME} ${WRKSRC}/rocksndiamonds ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/rocksndiamonds.1 \
		${PREFIX}/${PKGMANDIR}/man6/rocksndiamonds.6
	${INSTALL_DATA_DIR} ${SHAREDIR}
	# auto-generated PLIST
	-${RM} -f ${WRKDIR}/PLIST.F ${WRKDIR}/PLIST.D
	cd ${WRKSRC} &&							\
	for d in sounds graphics levels music; do 			\
		${FIND} $${d} -type d -print | { while read subdir; do	\
			${INSTALL_DATA_DIR}  ${SHAREDIR}/$${subdir};	\
			${ECHO} "@dirrm ${SHARESUBDIR}/$${subdir}";	\
		done ; } | ${SORT} -r >> ${WRKDIR}/PLIST.D;		\
		${FIND} $${d} -type f -print | while read f; do		\
			${INSTALL_DATA} $${f} ${SHAREDIR}/$${f};	\
			${ECHO} ${SHARESUBDIR}/$${f} >> ${WRKDIR}/PLIST.F;\
		done ;							\
	done

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
