# $NetBSD: Makefile,v 1.17 2006/01/21 18:57:41 jlam Exp $

DISTNAME=	quake106
PKGNAME=	quakedata-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.fu-berlin.de/pc/msdos/games/idgames/idstuff/quake/ \
		ftp://ftp.idsoftware.com/idstuff/quake/
EXTRACT_SUFX=	.zip

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.idsoftware.com/
COMMENT=	Game data files for Quake

BUILD_DEPENDS+=	lha-[0-9]*:../../archivers/lha

LICENSE+=		quakedata-license
RESTRICTED=		"This software is shareware."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

EXTRACT_ELEMENTS=	resource.*
EXTRACT_OPTS_ZIP=	-qo

WRKSRC=		${WRKDIR}
NO_BUILD=	YES

post-extract:
	cd ${WRKSRC}; ${CAT} resource.dat resource.1 > resource.exe
	cd ${WRKDIR}; lha xfq resource.exe id1/pak0.pak

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/quake/id1
	${INSTALL_DATA} ${WRKSRC}/id1/pak0.pak ${PREFIX}/share/quake/id1

.include "../../mk/bsd.pkg.mk"
