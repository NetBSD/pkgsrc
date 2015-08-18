# $NetBSD: Makefile,v 1.12 2015/08/18 07:31:08 wiz Exp $

DISTNAME=		moon-buggy-1.0.51
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://m.seehuhn.de/programs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.seehuhn.de/pages/moon-buggy
COMMENT=		Game on the Moon
LICENSE=		gnu-gpl-v2

USE_GAMESGROUP=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}/games

USE_TOOLS+=		makeinfo
INFO_FILES=		yes

BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/games/moon-buggy ${GAMEDIR_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/moon-buggy/mbscore ${GAMEDATA_PERMS}
SPECIAL_PERMS+=		${PREFIX}/bin/moon-buggy ${SETGID_GAMES_PERMS}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
