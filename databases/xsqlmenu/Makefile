# $NetBSD: Makefile,v 1.4 2002/09/21 00:26:53 jlam Exp $
#

DISTNAME=	xsqlmenu-2.10
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.jlab.org/~saw/xsqlmenu/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.jlab.org/~saw/xsqlmenu/
COMMENT=	X based GUI for MySQL

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_GMAKE=	yes
MAKE_ENV+=	MAKE=${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsqlmenu ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.README ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.lsm ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/[A-Z][A-Z]* ${PREFIX}/share/doc/xsqlmenu

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xforms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
