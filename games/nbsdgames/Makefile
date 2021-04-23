# $NetBSD: Makefile,v 1.4 2021/04/23 08:13:16 nia Exp $

DISTNAME=	nbsdgames-v4.0
PKGNAME=	${DISTNAME:S/-v/-/1}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=abakh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abakh/nbsdgames
COMMENT=	New BSD Games - a package of 17 text-based modern games
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c99

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

INSTALLATION_DIRS+=	bin

.if empty(UNPRIVILEGED:M[yY][eE][sS])
.  for game in pipes jewels fisher muncher miketron darrt
SPECIAL_PERMS+=		bin/${game} ${SETGID_GAMES_PERMS}
.  endfor
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/pp_scores ${GAMEDATA_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/jw_scores ${GAMEDATA_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/fsh_scores ${GAMEDATA_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/mnch_scores ${GAMEDATA_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/mt_scores ${GAMEDATA_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/drt_scores ${GAMEDATA_PERMS}
.endif

.include "../../mk/bsd.pkg.mk"
