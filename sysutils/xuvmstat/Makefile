# $NetBSD: Makefile,v 1.6 2003/03/29 12:42:34 jmmv Exp $
#

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	xuvmstat-20010220
WRKSRC=		${WRKDIR}/xuvmstat
CATEGORIES=	sysutils
MASTER_SITES=	http://www.netbsd.org/~chuck/gz/

MAINTAINER=	wiz@netbsd.org
COMMENT=	graphical display for the current UVM status

MAKE_ENV+=	X11BASE=${X11BASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xuvmstat ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xuvmstat
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/xuvmstat

.include "../../mk/bsd.pkg.mk"
