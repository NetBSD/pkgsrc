# $NetBSD: Makefile,v 1.1.1.1 2005/03/04 12:05:13 wiz Exp $
#

DISTNAME=		rinfo23
PKGNAME=		ROMInfo-2.3
CATEGORIES=		emulation
MASTER_SITES=		http://www.logiqx.com/Tools/ROMInfo/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/ROMInfo/ROMInfo.shtml
COMMENT=		Identify arcade ROM sets

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		rominfo

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rominfo ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ROMInfo
	${INSTALL_DATA} ${WRKSRC}/rominfo.txt ${PREFIX}/share/doc/ROMInfo

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
