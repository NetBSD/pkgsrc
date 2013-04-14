# $NetBSD: Makefile,v 1.23 2013/04/14 02:01:30 dholland Exp $
#

DISTNAME=	Maelstrom-3.0.5
PKGNAME=	maelstrom-sdl-3.0.5
PKGREVISION=	8
CATEGORIES=	games x11
MASTER_SITES=	http://www.devolution.com/~slouken/Maelstrom/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.devolution.com/~slouken/Maelstrom/
COMMENT=	High resolution version of Asteroids (SDL version)

CONFLICTS=		maelstrom-x11-[0-9]* maelstrom-[0-9]*

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_GAMESGROUP=		yes

MAKE_ENV+=		CP=${CP:Q}
LIBS.SunOS+=		-lsocket -lnsl

.if 0
# setgid
CFLAGS+=		-DMAELSTROM_SETGID
SPECIAL_PERMS+=		${PREFIX}/bin/Maelstrom ${SETGID_GAMES_PERMS}
SCOREFILE_PERMS=	${GAMEDATA_PERMS}
.else
# not setgid, world-writeable score file (XXX)
SCOREFILE_PERMS=	games games 666
.endif
BUILD_DEFS+=		SCOREFILE_PERMS

# Put scorefile in VARBASE.
SCOREDIR=		${VARBASE}/games
SCOREFILE=		${SCOREDIR}/Maelstrom-Scores
ORIGSCOREFILE=		${PREFIX}/share/Maelstrom/Maelstrom-Scores
REQD_FILES_PERMS+=	${ORIGSCOREFILE} ${SCOREFILE} ${SCOREFILE_PERMS}
CFLAGS+=		-DMAELSTROM_SCOREDIR=\"${SCOREDIR:Q}\"
BUILD_DEFS+=		VARBASE SCOREFILE

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/doc/Maelstrom/Docs/Makefile \
		${DESTDIR}${PREFIX}/share/doc/Maelstrom/Docs/Makefile.in \
		${DESTDIR}${PREFIX}/share/Maelstrom/Images/Makefile \
		${DESTDIR}${PREFIX}/share/Maelstrom/Images/Makefile.in

.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
