# $NetBSD: Makefile,v 1.12 2005/02/21 20:26:10 hubertf Exp $
#

DISTNAME=	xsqlmenu-2.10
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.jlab.org/~saw/xsqlmenu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.jlab.org/~saw/xsqlmenu/
COMMENT=	X based GUI for MySQL

USE_BUILDLINK3=	yes
USE_X11=	yes
USE_GNU_TOOLS+=	make
MAKE_ENV+=	MAKE=${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsqlmenu ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.README ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.lsm ${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/[A-Z][A-Z]* ${PREFIX}/share/doc/xsqlmenu

.include "../../mk/mysql.buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
