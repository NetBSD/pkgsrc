# $NetBSD: Makefile,v 1.8 2022/03/04 07:12:50 nia Exp $

DISTNAME=	nbsdgames-v5
PKGNAME=	${DISTNAME:S/-v/-/1}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=abakh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abakh/nbsdgames
COMMENT=	New BSD Games - a package of 17 text-based modern games
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c99
FAKE_NCURSES=	yes

BUILD_DEFS+=	VARBASE

.include "../../mk/curses.buildlink3.mk"

CFLAGS+=	${BUILDLINK_LDADD.curses}

.if empty(CURSES_TYPE:M*ncurses*)
CFLAGS+=	-DNO_MOUSE=1
.endif

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	GAMES_DIR=${DESTDIR}${PREFIX}/bin

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	config.h
SUBST_SED.paths+=	-e "s,/usr/games,${VARBASE}/games,g"
SUBST_NOOP_OK.paths=	yes

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps

.if empty(UNPRIVILEGED:M[yY][eE][sS])
.  for game in jewels sudoku mines reversi checkers battleship rabbithole \
    sos pipes fifteen memoblocks fisher muncher miketron redsquare darrt \
    snakeduel tugow
SPECIAL_PERMS+=		bin/${game} ${SETGID_GAMES_PERMS}
.  endfor
.  for file in pipes_scores jewels_scores miketron_scores \
	muncher_scores fisher_scores darrt_scores
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/${file} ${GAMEDATA_PERMS}
.  endfor
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/nbsdgames.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/nbsdgames.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
