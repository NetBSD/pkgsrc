# $NetBSD: Makefile,v 1.30 2018/01/14 15:26:49 rillig Exp $

DISTNAME=	xpat2-1.07
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/solitaires/}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	kuebart@mathematik.uni-ulm.de
COMMENT=	X11 solitaire game with 14 variations

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	imake pax

MAKE_ENV+=	XPMDIR=${BUILDLINK_PREFIX.libXpm} XMKMF=${XMKMF_CMD:Q}

USE_GAMESGROUP=		yes
SPECIAL_PERMS+=		bin/xpat2 ${SETGID_GAMES_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/xpat.log ${GAMEDATA_PERMS}
MAKE_DIRS=		/var/games

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
#.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
