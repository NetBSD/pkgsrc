# $NetBSD: Makefile,v 1.5 2001/07/27 11:16:20 wiz Exp $
#

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	xuvmstat-20010220
CATEGORIES=	sysutils
MASTER_SITES=	http://www.netbsd.org/~chuck/gz/

MAINTAINER=	wiz@netbsd.org
COMMENT=	graphical display for the current UVM status

MAKE_ENV+=	X11BASE=${X11BASE}

WRKSRC=		${WRKDIR}/xuvmstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xuvmstat ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xuvmstat
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/xuvmstat

.include "../../mk/bsd.pkg.mk"
