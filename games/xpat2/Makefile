# $NetBSD: Makefile,v 1.6 2001/11/19 23:27:51 jlam Exp $
# FreeBSD: ports/games/xpat2/Makefile,v 1.11 2000/04/14 12:27:59 asami Exp

DISTNAME=	xpat2-1.06
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/solitaires/}

MAINTAINER=	kuebart@mathematik.uni-ulm.de
COMMENT=	X11 solitaire game with 14 variations

USE_X11BASE=	YES

# This package uses imake, but invokes it directly as part of the build
# procedure.
#
#USE_IMAKE=	YES

EVAL_PREFIX=	XPMDIR=xpm
MAKE_ENV+=	XPMDIR="${XPMDIR}" XMKMF="${XMKMF}"

SUPPORT_FILES_PERMS=	/dev/null /var/games/xpat.log games games 0644
MAKE_DIRS=		/var/games

post-install:
	${CHOWN} root.games ${PREFIX}/bin/xpat2
	${CHMOD} 2555 ${PREFIX}/bin/xpat2
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
