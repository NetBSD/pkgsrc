# $NetBSD: Makefile,v 1.1.1.1 2005/03/04 12:05:12 wiz Exp $
#

DISTNAME=		datlib22
PKGNAME=		DatLib-2.2
CATEGORIES=		emulation
MASTER_SITES=		http://www.logiqx.com/Tools/DatLib/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/DatLib/DatLib.shtml
COMMENT=		Data file library for some emulation tools

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		datlib

MAKE_ENV+=		RANLIB=${RANLIB:Q}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/DatLib
	${INSTALL_DATA_DIR} ${PREFIX}/include/DatLib/hash
	${INSTALL_DATA_DIR} ${PREFIX}/include/DatLib/mame
	${INSTALL_DATA_DIR} ${PREFIX}/include/DatLib/misc
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${PREFIX}/include/DatLib
	${INSTALL_DATA} ${WRKSRC}/src/hash/*.h ${PREFIX}/include/DatLib/hash
	${INSTALL_DATA} ${WRKSRC}/src/mame/*.h ${PREFIX}/include/DatLib/mame
	${INSTALL_DATA} ${WRKSRC}/src/misc/*.h ${PREFIX}/include/DatLib/misc
	${INSTALL_LIB} ${WRKSRC}/obj/libdatlib.a ${PREFIX}/lib/libdatlib.a
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/DatLib
	${INSTALL_DATA} ${WRKSRC}/datlib.txt ${PREFIX}/share/doc/DatLib

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
