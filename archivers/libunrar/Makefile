# $NetBSD: Makefile,v 1.2 2024/01/24 23:44:38 adam Exp $

.include "../../archivers/unrar/Makefile.common"
PKGNAME=	${DISTNAME:S/^/lib/:S/src//}

BUILD_TARGET=		lib
INSTALLATION_DIRS=	include lib
CXXFLAGS+=		-DRARDLL

.include "../../mk/bsd.prefs.mk"

.if ${SHLIB_TYPE} == "dylib"
SOEXT=	dylib
.else
SOEXT=	so
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/dll.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/os.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/raros.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libunrar.so ${DESTDIR}${PREFIX}/lib/libunrar.${SOEXT}
.if ${OPSYS} == "Darwin"
	install_name_tool -id ${PREFIX}/lib/libunrar.${SOEXT} \
		${DESTDIR}${PREFIX}/lib/libunrar.${SOEXT}
.endif

.include "../../mk/bsd.pkg.mk"
