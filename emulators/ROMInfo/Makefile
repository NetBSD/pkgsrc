# $NetBSD: Makefile,v 1.16 2008/03/03 19:21:37 jlam Exp $
#

DISTNAME=		rinfo27
PKGNAME=		ROMInfo-2.7
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
EXTRACT_OPTS_ZIP=	-Laaqo
INSTALLATION_DIRS=	bin

PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rominfo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ROMInfo
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/ROMInfo

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
