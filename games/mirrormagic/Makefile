# $NetBSD: Makefile,v 1.31 2012/10/06 11:54:47 asau Exp $
#

DISTNAME=		mirrormagic-2.0.2
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://www.artsoft.org/RELEASES/unix/mirrormagic/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.artsoft.org/mirrormagic/
COMMENT=		Nice little puzzle game with color graphics and sound

CONFLICTS=		mirrormagic-sdl-[1-9]*

USE_TOOLS+=		gmake pax
PLIST_SRC=		${WRKDIR}/PLIST PLIST

# if you change SCORE_PATH, don't forget to change patch-aa, too
SCORE_PATH=		/var/games/mirrormagic

SETGIDGAME=		yes
OWN_DIRS_PERMS=		${SCORE_PATH} ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH}/scores				\
				${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH}/scores/classic_deflektor		\
				${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH}/scores/classic_mindbender		\
				${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

SPECIAL_PERMS=		bin/mirrormagic ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS=	bin share/mirrormagic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mirrormagic ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -rw graphics levels music sounds \
		${DESTDIR}${PREFIX}/share/mirrormagic/

	${RM} -f ${WRKDIR}/PLIST
.for levdir in Classic_Games
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/mirrormagic/levels/${levdir} -type f -print \
		>>${WRKDIR}/PLIST
.endfor
.for directory in graphics music sounds
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/mirrormagic/${directory} -type f -print \
		>>${WRKDIR}/PLIST
.endfor

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
