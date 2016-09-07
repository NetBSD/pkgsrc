# $NetBSD: Makefile,v 1.19 2016/09/07 13:25:45 mef Exp $
#

DISTNAME=		rinfo28
PKGNAME=		ROMInfo-2.8
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
EXTRACT_OPTS_ZIP=	-aaqo
INSTALLATION_DIRS=	bin
AUTO_MKDIRS=		yes

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rominfo ${DESTDIR}${PREFIX}/bin
#	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ROMInfo
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/ROMInfo

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
