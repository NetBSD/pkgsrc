# $NetBSD: Makefile,v 1.1.1.1 2005/03/04 12:05:13 wiz Exp $
#

DISTNAME=		mdiff216
PKGNAME=		MAMEDiff-2.16
CATEGORIES=		emulation
MASTER_SITES=		http://www.logiqx.com/Tools/MAMEDiff/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/MAMEDiff/MAMEDiff.shtml
COMMENT=		Compare MAME rom sets of different releases

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		mamediff

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mamediff ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/MAMEDiff
	${INSTALL_DATA} ${WRKSRC}/mamediff.txt ${PREFIX}/share/doc/MAMEDiff

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
