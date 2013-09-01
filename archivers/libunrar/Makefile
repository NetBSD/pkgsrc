# $NetBSD: Makefile,v 1.1 2013/09/01 08:28:29 wiz Exp $

.include "../../archivers/unrar/Makefile.common"
PKGNAME=	${DISTNAME:S/^/lib/:S/src//}

BUILD_TARGET=		lib
INSTALLATION_DIRS=	include lib
CXXFLAGS+=		-DRARDLL

do-install:
	${INSTALL_DATA} ${WRKSRC}/dll.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/os.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/raros.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libunrar.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
