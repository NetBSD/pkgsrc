# $NetBSD: Makefile,v 1.10 2006/01/20 23:41:29 jlam Exp $
#

DISTNAME=		rbuild27
PKGNAME=		ROMBuild-2.7
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/ROMBuild/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/ROMBuild/ROMBuild.shtml
COMMENT=		Arcade ROM manipulation tool

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		rombuild
EXTRACT_OPTS_ZIP=	-Laaqo
INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rombuild ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ROMBuild
	${INSTALL_DATA} ${WRKSRC}/rombuild.txt ${PREFIX}/share/doc/ROMBuild

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
