# $NetBSD: Makefile,v 1.24 2009/04/17 08:21:18 wiz Exp $

DISTNAME=	xpat2-1.07
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/solitaires/}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	kuebart@mathematik.uni-ulm.de
COMMENT=	X11 solitaire game with 14 variations

MAKE_JOBS_SAFE=		no
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	imake

MAKE_ENV+=	XPMDIR=${BUILDLINK_PREFIX.libXpm:Q} XMKMF=${XMKMF_CMD:Q}

CONF_FILES_PERMS=	/dev/null /var/games/xpat.log ${GAMEOWN} ${GAMEGRP} ${GAMEMODE}
MAKE_DIRS=		/var/games

post-install:
	${CHOWN} ${GAMEOWN}.${GAMEGRP} ${PREFIX}/bin/xpat2
	${CHMOD} ${GAMEMODE} ${PREFIX}/bin/xpat2

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
