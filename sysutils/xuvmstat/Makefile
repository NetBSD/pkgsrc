# $NetBSD: Makefile,v 1.14 2005/09/13 12:43:48 wiz Exp $
#

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	xuvmstat-20050909
CATEGORIES=	sysutils
MASTER_SITES=	http://www.NetBSD.org/~chuck/gz/

MAINTAINER=	wiz@NetBSD.org
COMMENT=	Graphical display for the current UVM status

WRKSRC=		${WRKDIR}/xuvmstat

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xuvmstat ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xuvmstat
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/xuvmstat

.include "../../mk/bsd.pkg.mk"
