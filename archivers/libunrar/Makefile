# $NetBSD: Makefile,v 1.3 2025/05/06 07:46:32 wiz Exp $

.include "../../archivers/unrar/Makefile.common"
PKGNAME=	${DISTNAME:S/^/lib/:S/src//}

BUILD_TARGET=		lib
INSTALLATION_DIRS=	include lib
CXXFLAGS+=		-DRARDLL

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/dll.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/os.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/raros.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libunrar.so ${DESTDIR}${PREFIX}/lib/libunrar.${SHLIB_EXT}
.if ${OPSYS} == "Darwin"
	install_name_tool -id ${PREFIX}/lib/libunrar.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib/libunrar.${SHLIB_EXT}
.endif

.include "../../mk/bsd.pkg.mk"
