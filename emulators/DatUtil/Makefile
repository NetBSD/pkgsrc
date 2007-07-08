# $NetBSD: Makefile,v 1.22 2007/07/08 09:42:33 wiz Exp $
#

DISTNAME=		dutil231
PKGNAME=		DatUtil-2.31
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/DatUtil/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/DatUtil/DatUtil.php
COMMENT=		Create and convert emulator rom checksum files

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
BUILD_TARGET=		datutil
EXTRACT_OPTS_ZIP=	-Laaqo

INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datutil ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/DatUtil
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/DatUtil

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
