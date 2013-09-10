# $NetBSD: Makefile,v 1.22 2013/09/10 14:45:05 joerg Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/-//}
PKGNAME=	xuvmstat-20050909
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.NetBSD.org/~chuck/gz/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphical display for the current UVM status

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}/xuvmstat

INSTALLATION_DIRS=	bin share/doc/xuvmstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xuvmstat ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/xuvmstat

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
