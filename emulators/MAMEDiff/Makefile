# $NetBSD: Makefile,v 1.15 2006/09/09 02:41:59 obache Exp $
#

DISTNAME=		mdiff224
PKGNAME=		MAMEDiff-2.24
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/MAMEDiff/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/MAMEDiff/MAMEDiff.shtml
COMMENT=		Compare MAME rom sets of different releases

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
BUILD_TARGET=		mamediff
EXTRACT_OPTS_ZIP=	-Laaqo
INSTALLATION_DIRS=	bin

BUILDLINK_API_DEPENDS.DatLib+=	DatLib>=2.13

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mamediff ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/MAMEDiff
	${INSTALL_DATA} ${WRKSRC}/mamediff.txt ${PREFIX}/share/doc/MAMEDiff

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
