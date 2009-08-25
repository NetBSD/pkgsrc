# $NetBSD: Makefile,v 1.25 2009/08/25 11:56:36 wiz Exp $
#

DISTNAME=		dutil232
PKGNAME=		DatUtil-2.32
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/DatUtil/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/DatUtil/DatUtil.php
COMMENT=		Create and convert emulator rom checksum files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
BUILD_TARGET=		datutil
EXTRACT_OPTS_ZIP=	-aaqo

INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datutil ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/DatUtil
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/DatUtil

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.DatLib+=	DatLib>=2.21
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
