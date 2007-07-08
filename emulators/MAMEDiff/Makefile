# $NetBSD: Makefile,v 1.18 2007/07/08 09:42:33 wiz Exp $
#

DISTNAME=		mdiff226
PKGNAME=		MAMEDiff-2.26
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/MAMEDiff/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/MAMEDiff/MAMEDiff.php
COMMENT=		Compare MAME rom sets of different releases

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
BUILD_TARGET=		mamediff
EXTRACT_OPTS_ZIP=	-Laaqo
INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mamediff ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/MAMEDiff
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/MAMEDiff

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
