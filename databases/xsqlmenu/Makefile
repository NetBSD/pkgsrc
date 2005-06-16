# $NetBSD: Makefile,v 1.16 2005/06/16 06:57:44 jlam Exp $
#

DISTNAME=	xsqlmenu-2.10
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.jlab.org/~saw/xsqlmenu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.jlab.org/~saw/xsqlmenu/
COMMENT=	X based GUI for MySQL

USE_TOOLS+=	gmake
MAKE_ENV+=	MAKE=${MAKE_PROGRAM}

INSTALLATION_DIRS=	bin

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
