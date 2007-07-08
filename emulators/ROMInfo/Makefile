# $NetBSD: Makefile,v 1.15 2007/07/08 09:42:33 wiz Exp $
#

DISTNAME=		rinfo27
PKGNAME=		ROMInfo-2.7
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/ROMInfo/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/ROMInfo/ROMInfo.php
COMMENT=		Identify arcade ROM sets

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
BUILD_TARGET=		rominfo
EXTRACT_OPTS_ZIP=	-Laaqo
INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rominfo ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ROMInfo
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/ROMInfo

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
