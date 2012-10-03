# $NetBSD: Makefile,v 1.24 2012/10/03 12:55:08 asau Exp $
#

DISTNAME=		datlib221
PKGNAME=		DatLib-2.21
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/DatLib/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/DatLib/DatLib.php
COMMENT=		Data file library for some emulation tools

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
BUILD_TARGET=		datlib
EXTRACT_OPTS_ZIP=	-aaqo

MAKE_ENV+=		RANLIB=${RANLIB:Q}
INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/DatLib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/DatLib/hash
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/DatLib/mame
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/DatLib/misc
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${DESTDIR}${PREFIX}/include/DatLib
	${INSTALL_DATA} ${WRKSRC}/src/hash/*.h ${DESTDIR}${PREFIX}/include/DatLib/hash
	${INSTALL_DATA} ${WRKSRC}/src/mame/*.h ${DESTDIR}${PREFIX}/include/DatLib/mame
	${INSTALL_DATA} ${WRKSRC}/src/misc/*.h ${DESTDIR}${PREFIX}/include/DatLib/misc
	${INSTALL_LIB} ${WRKSRC}/obj/libdatlib.a ${DESTDIR}${PREFIX}/lib/libdatlib.a
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/DatLib
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/DatLib

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
