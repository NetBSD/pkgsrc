# $NetBSD: Makefile,v 1.4 2001/02/16 15:11:00 wiz Exp $
# FreeBSD Id: ports/games/xbat/Makefile,v 1.5 1999/08/25 06:04:41 obrien Exp

DISTNAME=	xev111
PKGNAME=	xbat-1.11
CATEGORIES=	games
MASTER_SITES=	http://www.nemoto.ecei.tohoku.ac.jp/~wai/Xbat/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.nemoto.ecei.tohoku.ac.jp/~wai/index_e.html
COMMENT=	XEVIOUS like shooting game

RESTRICTED=	Possible copyright infringement
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/Xev111
ALL_TARGET=	xbat

.include "../../mk/bsd.pkg.mk"
