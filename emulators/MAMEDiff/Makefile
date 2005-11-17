# $NetBSD: Makefile,v 1.9 2005/11/17 18:35:01 wiz Exp $
#

DISTNAME=		mdiff221
PKGNAME=		MAMEDiff-2.21
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/MAMEDiff/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/MAMEDiff/MAMEDiff.shtml
COMMENT=		Compare MAME rom sets of different releases

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		mamediff
EXTRACT_CMD_OPTS.zip=	-Laaqo
INSTALLATION_DIRS=	bin

BUILDLINK_DEPENDS.DatLib+=	DatLib>=2.11

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mamediff ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/MAMEDiff
	${INSTALL_DATA} ${WRKSRC}/mamediff.txt ${PREFIX}/share/doc/MAMEDiff

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
