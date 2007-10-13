# $NetBSD: Makefile,v 1.36 2007/10/13 12:58:47 adam Exp $

DISTNAME=	rocksndiamonds-3.2.4
CATEGORIES=	games x11
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://www.artsoft.org/rocksndiamonds/
COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban

PKG_DESTDIR_SUPPORT=	# wrong permissions in +INSTALL script

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man6

PKG_GROUPS+=	${GAMEGRP}
PKG_USERS+=	${GAMEOWN}:${GAMEGRP}
BUILD_DEFS+=	VARBASE SCORE_PATH

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
	${INSTALL_GAME} ${WRKSRC}/rocksndiamonds ${DESTDIR:Q}${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC}/rocksndiamonds.1 \
		${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man6/rocksndiamonds.6
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${SHAREDIR:Q}
	# auto-generated PLIST
	rm -f ${WRKDIR}/PLIST.F ${WRKDIR}/PLIST.D
	set -e;								\
	cd ${WRKSRC} &&							\
	for d in sounds graphics levels music; do 			\
		find "$${d}" -type d -print | { while read subdir; do	\
			${INSTALL_DATA_DIR} 				\
				${DESTDIR:Q}${SHAREDIR:Q}/"$${subdir}";	\
			${ECHO} "@dirrm ${SHARESUBDIR}/$${subdir}";	\
		done ; } | sort -r >> ${WRKDIR}/PLIST.D;		\
		find "$${d}" -type f -print | while read f; do		\
			${INSTALL_DATA} "$${f}"				\
				${DESTDIR:Q}${SHAREDIR:Q}/"$${f}";	\
			${ECHO} ${SHARESUBDIR}/"$${f}" >> ${WRKDIR}/PLIST.F;\
		done ;							\
	done

.include "../../mk/bsd.pkg.mk"
