# $NetBSD: Makefile,v 1.20 2010/01/27 20:58:05 joerg Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/-//}
PKGNAME=	xuvmstat-20050909
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.NetBSD.org/~chuck/gz/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphical display for the current UVM status

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}/xuvmstat

INSTALLATION_DIRS=	bin share/doc/xuvmstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xuvmstat ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/xuvmstat

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
