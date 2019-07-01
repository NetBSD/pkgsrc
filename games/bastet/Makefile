# $NetBSD: Makefile,v 1.18 2019/07/01 04:08:09 ryoon Exp $

DISTNAME=		bastet-0.43.1
PKGREVISION=		9
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=fph/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fph.altervista.org/prog/bastet.html
COMMENT=		Bastard Tetris
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake
BUILD_DEFS+=		VARBASE

USE_GAMESGROUP=		yes
SPECIAL_PERMS=		bin/bastet ${SETGID_GAMES_PERMS}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

USE_LANGUAGES=	c++

SUBST_CLASSES+=		vardir
SUBST_STAGE.vardir=	pre-configure
SUBST_FILES.vardir=	Config.cpp
SUBST_MESSAGE.vardir=	Fixing VARBASE.
SUBST_SED.vardir=	-e "s|/var/games|${VARBASE}/games|1"

REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/bastet.scores2 ${GAMEDATA_PERMS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bastet ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bastet.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
