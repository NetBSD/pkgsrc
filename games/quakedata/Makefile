# $NetBSD: Makefile,v 1.5 2001/02/16 15:10:58 wiz Exp $
# Based on FreeBSD ports/games/quakeserver
# FreeBSD: ports/games/quakeserver/Makefile,v 1.20 1999/08/31 06:44:23 mharo Exp
#

DISTNAME=	quake106
PKGNAME=	quakedata-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/quake/planetquake/threewave/unix/ \
		ftp://ftp.idsoftware.com/idstuff/quake/
EXTRACT_SUFX=	.zip

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.idsoftware.com/
COMMENT=	Game data files for Quake

BUILD_DEPENDS=	unzip:../../archivers/unzip
BUILD_DEPENDS+=	lha:../../archivers/lha

LICENSE+=		shareware
RESTRICTED=		"This software is shareware"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EXTRACT_CMD=	unzip -q -o ${DOWNLOADED_DISTFILE} -d ${WRKDIR} resource.*
NO_WRKSUBDIR=	YES
NO_BUILD=	YES

post-extract:
	cd ${WRKSRC}; ${CAT} resource.dat resource.1 > resource.exe
	cd ${WRKDIR}; lha xfq resource.exe id1/pak0.pak

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/quake/id1
	${INSTALL_DATA} ${WRKSRC}/id1/pak0.pak ${PREFIX}/share/quake/id1

.include "../../mk/bsd.pkg.mk"
