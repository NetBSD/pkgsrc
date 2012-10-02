# $NetBSD: Makefile,v 1.29 2012/10/02 21:25:55 asau Exp $
#

DISTNAME=	xsqlmenu-2.10
PKGREVISION=	11
CATEGORIES=	databases
MASTER_SITES=	http://www.jlab.org/~saw/xsqlmenu/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jlab.org/~saw/xsqlmenu/
COMMENT=	X based GUI for MySQL

USE_TOOLS+=	gmake
MAKE_ENV+=	MAKE=${MAKE_PROGRAM:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsqlmenu ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.README \
		${DESTDIR}${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.lsm \
		${DESTDIR}${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/[A-Z][A-Z]* \
		${DESTDIR}${PREFIX}/share/doc/xsqlmenu

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
