# $NetBSD: Makefile,v 1.3 2002/04/17 04:45:12 fredb Exp $
#

DISTNAME=	xsqlmenu-2.10
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.jlab.org/~saw/xsqlmenu/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.jlab.org/~saw/xsqlmenu/
COMMENT=	X based GUI for MySQL

DEPENDS+=	mysql-client-3.*:../mysql-client
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	xforms>=0.9999:../../x11/xforms

USE_GMAKE=	yes
USE_XPM=	yes
MAKE_ENV+=	MAKE=gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsqlmenu ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.README ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.lsm ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/[A-Z][A-Z]* ${PREFIX}/share/doc/xsqlmenu

.include "../../mk/bsd.pkg.mk"
