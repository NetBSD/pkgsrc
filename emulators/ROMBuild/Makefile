# $NetBSD: Makefile,v 1.20 2014/10/07 20:49:47 shattered Exp $
#

DISTNAME=		rbuild214
PKGNAME=		ROMBuild-2.14
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/ROMBuild/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/ROMBuild/ROMBuild.php
COMMENT=		Arcade ROM manipulation tool

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
BUILD_TARGET=		rombuild
EXTRACT_OPTS_ZIP=	-aaqo
INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rombuild ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ROMBuild
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/ROMBuild

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
