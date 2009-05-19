# $NetBSD: Makefile,v 1.23 2009/05/19 08:59:15 wiz Exp $

DISTNAME=	quake106
PKGNAME=	quakedata-1.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.fu-berlin.de/pc/msdos/games/idgames/idstuff/quake/ \
		ftp://ftp.idsoftware.com/idstuff/quake/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.idsoftware.com/
COMMENT=	Game data files for Quake
LICENSE=		quakedata-license

RESTRICTED=		This software is shareware.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

BUILD_DEPENDS+=	lha-[0-9]*:../../archivers/lha

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ELEMENTS=	resource.*
EXTRACT_OPTS_ZIP=	-qo

WRKSRC=		${WRKDIR}
NO_BUILD=	YES
USE_TOOLS+=	lha

post-extract:
	cd ${WRKSRC} && ${CAT} resource.dat resource.1 > resource.exe
	cd ${WRKDIR} && ${LHA} xfq resource.exe id1/pak0.pak

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/quake/id1
	${INSTALL_DATA} ${WRKSRC}/id1/pak0.pak \
		${DESTDIR}${PREFIX}/share/quake/id1

.include "../../mk/bsd.pkg.mk"
