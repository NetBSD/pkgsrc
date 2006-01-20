# $NetBSD: Makefile,v 1.16 2006/01/20 23:41:29 jlam Exp $
#

DISTNAME=		dutil227
PKGNAME=		DatUtil-2.27
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/DatUtil/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/DatUtil/DatUtil.shtml
COMMENT=		Create and convert emulator rom checksum files

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		datutil
EXTRACT_OPTS_ZIP=	-Laaqo

INSTALLATION_DIRS=	bin

BUILDLINK_DEPENDS.DatLib+=	DatLib>=2.15

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datutil ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/DatUtil
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/DatUtil

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
