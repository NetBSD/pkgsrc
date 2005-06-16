# $NetBSD: Makefile,v 1.7 2005/06/16 06:57:50 jlam Exp $
#

DISTNAME=		rbuild26
PKGNAME=		ROMBuild-2.6
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
EXTRACT_CMD_OPTS.zip=	-Laaqo
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
