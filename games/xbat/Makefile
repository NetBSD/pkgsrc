# $NetBSD: Makefile,v 1.8 2004/12/03 15:14:58 wiz Exp $
# FreeBSD Id: ports/games/xbat/Makefile,v 1.5 1999/08/25 06:04:41 obrien Exp

DISTNAME=	xev111
PKGNAME=	xbat-1.11
CATEGORIES=	games
MASTER_SITES=	http://www.nemoto.ecei.tohoku.ac.jp/~wai/Xbat/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.nemoto.ecei.tohoku.ac.jp/~wai/index_e.html
COMMENT=	XEVIOUS like shooting game

RESTRICTED=	Possible copyright infringement
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=		${WRKDIR}/Xev111
USE_IMAKE=	yes
BUILD_TARGET=	xbat

.include "../../mk/bsd.pkg.mk"
