# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:50 jlam Exp $
#

DISTNAME=		datlib25
PKGNAME=		DatLib-2.5
CATEGORIES=		emulators
MASTER_SITES=		http://www.logiqx.com/Tools/DatLib/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.logiqx.com/Tools/DatLib/DatLib.shtml
COMMENT=		Data file library for some emulation tools

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		datlib
EXTRACT_CMD_OPTS.zip=	-Laaqo

MAKE_ENV+=		RANLIB=${RANLIB:Q}
INSTALLATION_DIRS=	lib

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
