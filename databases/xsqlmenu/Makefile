# $NetBSD: Makefile,v 1.2 2001/04/15 01:11:16 hubertf Exp $
#

DISTNAME=	xsqlmenu-2.10
CATEGORIES=	databases
MASTER_SITES=	http://www.jlab.org/~saw/xsqlmenu/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.jlab.org/~saw/xsqlmenu/
COMMENT=	X based GUI for MySQL

DEPENDS+=	xforms-0.8*:../../x11/xforms
DEPENDS+=	mysql-client-3.*:../mysql-client

USE_GMAKE=	yes
MAKE_ENV+=	MAKE=gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsqlmenu ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.README ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.lsm ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/[A-Z][A-Z]* ${PREFIX}/share/doc/xsqlmenu

.include "../../mk/bsd.pkg.mk"
