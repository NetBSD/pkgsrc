# $NetBSD: Makefile,v 1.20 2008/01/19 09:16:21 wiz Exp $

DISTNAME=		Maelstrom-1.4.3-L2.0.6-src.tar.gz
PKGNAME=		maelstrom-x11-2.0.6
PKGREVISION=		2
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
USE_X11BASE=		YES
MAKE_ENV+=		BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} XPMDIR=${BUILDLINK_PREFIX.libXpm}
MAKE_ENV+=		GAMEOWN=${GAMEOWN} GAMEGRP=${GAMEGRP}
MAKE_ENV+=		GAMEMODE=${GAMEMODE} GAMEDATAMODE=${GAMEDATAMODE}
MAKE_ENV+=		VARBASE=${VARBASE}

MAKE_DIRS_PERMS+=	${VARBASE}/games ${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
CONF_FILES_PERMS+=	${PREFIX}/share/maelstrom/Maelstrom-Scores \
	${VARBASE}/games/Maelstrom-Scores ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}

post-install:
	cd ${PREFIX}/share/maelstrom && \
		${PAX} -O -pm -zrf ${DISTDIR}/${ESOUND} && \
		${PAX} -O -pm -zrf ${DISTDIR}/${STREK} && \
		${PAX} -O -pm -zrf ${DISTDIR}/${SWARS}
	${CHOWN} ${GAMEOWN}:${GAMEGRP} ${PREFIX}/bin/Maelstrom
	${CHMOD} ${GAMEMODE} ${PREFIX}/bin/Maelstrom
	${INSTALL_DATA} ${WRKSRC}/README.* ${PREFIX}/share/maelstrom
	${INSTALL_PROGRAM} ${WRKSRC}/netplayd/netplayd ${PREFIX}/bin/Maelstrom_netplayd

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
