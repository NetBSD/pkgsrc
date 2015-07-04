# $NetBSD: Makefile,v 1.28 2015/07/04 16:18:34 joerg Exp $

DISTNAME=		Maelstrom-1.4.3-L2.0.6-src.tar.gz
PKGNAME=		maelstrom-x11-2.0.6
PKGREVISION=		4
CATEGORIES=		games x11
MASTER_SITES+=		ftp://ftp.devolution.com/pub/maelstrom/
MASTER_SITES+=		ftp://ftp.devolution.com/pub/maelstrom/Maelstrom-binaries/
MASTER_SITES+=		ftp://ftp.devolution.com/pub/maelstrom/Add-Ons/
DISTFILES=		${DISTNAME} ${STREK} ${SWARS} ${ESOUND}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ambrosiasw.com/Products/Maelstrom.html
COMMENT=	High resolution graphics version of Asteroids (X11 version)

ESOUND=			Maelstrom-Sounds-L2.0.0.tar.gz
STREK=			Star_Trek.tar.gz
SWARS=			Star_Wars.tar.gz

CONFLICTS=		maelstrom-[0-9]* maelstrom-sdl-[0-9]*

EXTRACT_ONLY=		${DISTNAME}

WRKSRC=			${WRKDIR}/Maelstrom
USE_LANGUAGES=		c c++
USE_TOOLS+=		pax
LDFLAGS.SunOS+=		-lsocket -lnsl
LIBS.SunOS+=		-lsocket -lnsl
MAKE_FLAGS+=		EXTRALIBS=${LIBS:Q}
MAKE_ENV+=		BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} XPMDIR=${BUILDLINK_PREFIX.libXpm}
MAKE_ENV+=		GAMEOWN=${GAMEOWN} GAMEGRP=${GAMEGRP}
MAKE_ENV+=		GAMEMODE=${GAMEMODE} GAMEDATAMODE=${GAMEDATAMODE}
MAKE_ENV+=		VARBASE=${VARBASE}

USE_GAMESGROUP=		yes
SCOREDIR=		${VARBASE}/games
SCOREFILE=		${SCOREDIR}/Maelstrom-Scores
ORIGSCOREFILE=		${PREFIX}/share/maelstrom/Maelstrom-Scores
MAKE_DIRS_PERMS+=	${SCOREDIR} ${GAMEDIR_PERMS}
REQD_FILES_PERMS+=	${ORIGSCOREFILE} ${SCOREFILE} ${GAMEDATA_PERMS}
BUILD_DEFS+=		VARBASE SCOREFILE

SPECIAL_PERMS+=		bin/Maelstrom ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS+=	bin share/maelstrom

post-install:
	cd ${DESTDIR}${PREFIX}/share/maelstrom && \
		pax -O -pm -zrf ${DISTDIR}/${ESOUND} && \
		pax -O -pm -zrf ${DISTDIR}/${STREK} && \
		pax -O -pm -zrf ${DISTDIR}/${SWARS}
	${INSTALL_DATA} ${WRKSRC}/README.* ${DESTDIR}${PREFIX}/share/maelstrom
	${INSTALL_PROGRAM} ${WRKSRC}/netplayd/netplayd \
		${DESTDIR}${PREFIX}/bin/Maelstrom_netplayd

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
