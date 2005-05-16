# $NetBSD: Makefile,v 1.15 2005/05/16 18:16:06 jlam Exp $

DISTNAME=	xpat2-1.07
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/solitaires/}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	kuebart@mathematik.uni-ulm.de
COMMENT=	X11 solitaire game with 14 variations

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGINSTALL=	YES
USE_X11BASE=	YES

# This package uses imake, but invokes it directly as part of the build
# procedure.
#
#USE_IMAKE=	YES

MAKE_ENV+=	XPMDIR=${BUILDLINK_PREFIX.xpm:Q} XMKMF=${XMKMF:Q}

SUPPORT_FILES_PERMS=	/dev/null /var/games/xpat.log ${GAMEOWN} ${GAMEGRP} ${GAMEMODE}
MAKE_DIRS=		/var/games

post-install:
	${CHOWN} ${GAMEOWN}.${GAMEGRP} ${PREFIX}/bin/xpat2
	${CHMOD} ${GAMEMODE} ${PREFIX}/bin/xpat2

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
