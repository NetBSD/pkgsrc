# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:50 jlam Exp $
#

DISTNAME=		dutil217
PKGNAME=		DatUtil-2.17
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
EXTRACT_CMD_OPTS.zip=	-Laaqo

BUILDLINK_DEPENDS.DatLib+=	DatLib>=2.4

INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datutil ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/DatUtil
	${INSTALL_DATA} ${WRKSRC}/datutil.txt ${PREFIX}/share/doc/DatUtil

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
