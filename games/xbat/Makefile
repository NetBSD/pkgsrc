# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:23 joerg Exp $

DISTNAME=	xev111
PKGNAME=	xbat-1.11
PKGREVISION=	1
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
