# $NetBSD: Makefile,v 1.7 2021/07/20 21:04:28 fcambus Exp $

DISTNAME=	nbsdgames-v4.1.2
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

.if empty(UNPRIVILEGED:M[yY][eE][sS])
.  for game in jewels sudoku mines reversi checkers battleship rabbithole \
    sos pipes fifteen memoblocks fisher muncher miketron redsquare darrt \
    snakeduel
SPECIAL_PERMS+=		bin/${game} ${SETGID_GAMES_PERMS}
.  endfor
.  for file in pipes_scores jewels_scores miketron_scores \
	muncher_scores fisher_scores darrt_scores
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/${file} ${GAMEDATA_PERMS}
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
