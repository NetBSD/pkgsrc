# $NetBSD: Makefile,v 1.11 2012/10/06 11:54:32 asau Exp $

DISTNAME=		cbzone-sound
PKGNAME=		cbzone-2.0c
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.cdrom.com/pub/X11/R5contrib/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Simple classic game of 3D tank warfare

WRKSRC=			${WRKDIR}/cbzone
USE_TOOLS+=		gmake
USE_IMAKE=		yes

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMES_USER
BUILD_DEFS+=		GAMES_GROUP
BUILD_DEFS+=		GAMEDATAMODE

MAKE_DIRS_PERMS+=	${VARBASE}/games ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/cbzone.highscores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS+=		bin/cbzone.exec ${SETGID_GAMES_PERMS}

SUBST_CLASSES+=		scoredir
SUBST_STAGE.scoredir=	post-configure
SUBST_FILES.scoredir=	c_scores.c
SUBST_VARS.scoredir=	VARBASE

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
