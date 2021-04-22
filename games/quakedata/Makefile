# $NetBSD: Makefile,v 1.30 2021/04/22 09:23:58 nia Exp $

DISTNAME=	quake106
PKGNAME=	quakedata-1.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.fu-berlin.de/pc/msdos/games/idgames/idstuff/quake/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.idsoftware.com/
COMMENT=	Game data files for Quake
LICENSE=	quakedata-license

RESTRICTED=		This software is shareware.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

TOOL_DEPENDS+=		lhasa-[0-9]*:../../archivers/lhasa

EXTRACT_ELEMENTS=	resource.*

WRKSRC=		${WRKDIR}
NO_BUILD=	YES

post-extract:
	cd ${WRKSRC} && ${CAT} resource.dat resource.1 > resource.exe
	cd ${WRKDIR} && ${PREFIX}/bin/lha xfq resource.exe id1/pak0.pak

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/quake/id1
	${INSTALL_DATA} ${WRKSRC}/id1/pak0.pak \
		${DESTDIR}${PREFIX}/share/quake/id1

.include "../../mk/bsd.pkg.mk"
