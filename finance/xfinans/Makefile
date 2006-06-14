# $NetBSD: Makefile,v 1.12 2006/06/14 10:25:01 rillig Exp $
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
	${CP} ${WRKSRC}/XFinans.defaults ${PREFIX}/lib/X11/app-defaults/XFinans
	${CP} ${WRKSRC}/*.acc ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/xfin.ps ${PREFIX}/share/doc/Xfinans
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/Xfinans
	${CP} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/Xfinans
	${CP} ${WRKSRC}/hyperhelp ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/hyperhelp.index ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/finans.bkd ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/variables ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/categories ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/category_engine ${PREFIX}/share/examples/Xfinans
	${RM} -f ${PREFIX}/man/cat1/xfinans.0

.include "../../mk/bsd.pkg.mk"
