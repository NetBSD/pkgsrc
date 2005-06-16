# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:50 jlam Exp $
#

DISTNAME=		rinfo23
PKGNAME=		ROMInfo-2.3
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/ROMInfo/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/ROMInfo/ROMInfo.shtml
COMMENT=		Identify arcade ROM sets

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		rominfo
EXTRACT_CMD_OPTS.zip=	-Laaqo
INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rominfo ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ROMInfo
	${INSTALL_DATA} ${WRKSRC}/rominfo.txt ${PREFIX}/share/doc/ROMInfo

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
