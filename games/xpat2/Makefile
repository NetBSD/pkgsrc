# $NetBSD: Makefile,v 1.8 2002/10/10 12:56:00 wiz Exp $
# FreeBSD: ports/games/xpat2/Makefile,v 1.11 2000/04/14 12:27:59 asami Exp

DISTNAME=	xpat2-1.06
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/solitaires/}

MAINTAINER=	kuebart@mathematik.uni-ulm.de
COMMENT=	X11 solitaire game with 14 variations

USE_BUILDLINK2=	YES
USE_X11BASE=	YES

# This package uses imake, but invokes it directly as part of the build
# procedure.
#
#USE_IMAKE=	YES

MAKE_ENV+=	XPMDIR="${BUILDLINK_PREFIX.xpm}" XMKMF="${XMKMF}"

SUPPORT_FILES_PERMS=	/dev/null /var/games/xpat.log games games 0644
MAKE_DIRS=		/var/games

post-install:
	${CHOWN} root.games ${PREFIX}/bin/xpat2
	${CHMOD} 2555 ${PREFIX}/bin/xpat2

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
