# $NetBSD: Makefile,v 1.1.1.1 2001/02/19 12:15:16 wiz Exp $
#

DISTNAME=	xuvmstat20010217
PKGNAME=	${DISTNAME:S/2/-2/}
CATEGORIES=	sysutil
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
