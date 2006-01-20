# $NetBSD: Makefile,v 1.9 2006/01/20 23:41:30 jlam Exp $
#

DISTNAME=		zident27
PKGNAME=		ZIPIdent-2.7
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/ZIPIdent/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/ZIPIdent/ZIPIdent.shtml
COMMENT=		Identify arcade ROM sets

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		zipident
EXTRACT_OPTS_ZIP=	-Laaqo
INSTALLATION_DIRS=	bin

BUILDLINK_DEPENDS.DatLib+=	DatLib>=2.13

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zipident ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ZIPIdent
	${INSTALL_DATA} ${WRKSRC}/zipident.txt ${PREFIX}/share/doc/ZIPIdent

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
