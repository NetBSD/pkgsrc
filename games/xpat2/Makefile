# $NetBSD: Makefile,v 1.5 2001/02/16 15:11:03 wiz Exp $
# FreeBSD: ports/games/xpat2/Makefile,v 1.11 2000/04/14 12:27:59 asami Exp

DISTNAME=	xpat2-1.06
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/solitaires/}

MAINTAINER=	kuebart@mathematik.uni-ulm.de
COMMENT=	X11 solitaire game with 14 variations

USE_X11BASE=	YES
USE_XPM=	YES

EVAL_PREFIX=	XPMDIR=xpm
MAKE_ENV+=	XPMDIR="${XPMDIR}" XMKMF="${XMKMF}"

post-install:
	${CHOWN} root.games ${PREFIX}/bin/xpat2
	${CHMOD} 2555 ${PREFIX}/bin/xpat2
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
