# $NetBSD: Makefile,v 1.2 2005/03/14 16:20:58 wiz Exp $
#

DISTNAME=		zident24
PKGNAME=		ZIPIdent-2.4
CATEGORIES=		emulation
MASTER_SITES=		http://www.logiqx.com/Tools/ZIPIdent/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/ZIPIdent/ZIPIdent.shtml
COMMENT=		Identify arcade ROM sets

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		zipident
EXTRACT_CMD_OPTS.zip=	-Laaqo

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zipident ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ZIPIdent
	${INSTALL_DATA} ${WRKSRC}/zipident.txt ${PREFIX}/share/doc/ZIPIdent

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
