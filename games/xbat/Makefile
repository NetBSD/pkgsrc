# $NetBSD: Makefile,v 1.12 2006/12/27 13:37:37 joerg Exp $

DISTNAME=	xev111
PKGNAME=	xbat-1.11
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.nemoto.ecei.tohoku.ac.jp/~wai/Xbat/

MAINTAINER=	pkgsrc-users@NetBSD.org
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

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
