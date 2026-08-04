# $NetBSD: Makefile,v 1.19 2026/08/04 20:28:57 wiz Exp $

DISTNAME=	xbomb-2.2b
CATEGORIES=	games x11
MASTER_SITES=	https://www.gedanken.org.uk/software/xbomb/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gedanken.org.uk/software/xbomb/
COMMENT=	Square, hexagonal, and triangual minesweeper clone
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
BUILD_TARGET=		xbomb
MAKE_ENV+=		SCORE_PATH=${SCORE_PATH:Q}
INSTALL_MAKE_FLAGS+=	INSTDIR=${DESTDIR}${PREFIX}

OWN_DIRS_PERMS+=	${VARBASE}/games/xbomb \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

SETGIDGAME=	yes
SCORE_PATH=	${VARBASE}/games/xbomb

SPECIAL_PERMS+=	bin/xbomb ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 lib/X11/app-defaults
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH:Q}/xbomb3.hi ${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH:Q}/xbomb4.hi ${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH:Q}/xbomb6.hi ${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
