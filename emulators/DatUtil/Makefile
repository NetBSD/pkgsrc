# $NetBSD: Makefile,v 1.1.1.1 2005/03/04 12:05:13 wiz Exp $
#

DISTNAME=		dutil214
PKGNAME=		DatUtil-2.14
CATEGORIES=		emulation
MASTER_SITES=		http://www.logiqx.com/Tools/DatUtil/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/DatUtil/DatUtil.shtml
COMMENT=		Create and convert emulator rom checksum files

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		datutil

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datutil ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/DatUtil
	${INSTALL_DATA} ${WRKSRC}/datutil.txt ${PREFIX}/share/doc/DatUtil

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
