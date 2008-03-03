# $NetBSD: Makefile,v 1.16 2008/03/03 19:21:37 jlam Exp $
#

DISTNAME=		zident28
PKGNAME=		ZIPIdent-2.8
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/ZIPIdent/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/ZIPIdent/ZIPIdent.php
COMMENT=		Identify arcade ROM sets

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
BUILD_TARGET=		zipident
EXTRACT_OPTS_ZIP=	-Laaqo
INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zipident ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ZIPIdent
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/ZIPIdent

.include "../../devel/zlib/buildlink3.mk"
.include "../../emulators/DatLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
