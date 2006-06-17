# $NetBSD: Makefile,v 1.13 2006/06/17 18:01:17 rillig Exp $
#

DISTNAME=		xfinans-5.9
PKGREVISION=		2
CATEGORIES=		finance x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/financial/accounting/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.io.com/~acroyear/xfinans/
COMMENT=		Xfinans is a useful financial tracking, and account balancing tool

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot

WRKSRC=			${WRKDIR}/Xfinans
CONFIGURE_DIRS=		Src
USE_IMAKE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/app-defaults/XFinans
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Xfinans
	${INSTALL_DATA} ${WRKSRC}/XFinans.defaults ${PREFIX}/lib/X11/app-defaults/XFinans
	${INSTALL_DATA} ${WRKSRC}/*.acc ${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/xfin.ps ${PREFIX}/share/doc/Xfinans
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/Xfinans
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/Xfinans
	${INSTALL_DATA} ${WRKSRC}/hyperhelp ${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/hyperhelp.index ${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/finans.bkd ${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/variables ${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/categories ${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/category_engine ${PREFIX}/share/examples/Xfinans
	${RM} -f ${PREFIX}/man/cat1/xfinans.0

.include "../../mk/bsd.pkg.mk"
