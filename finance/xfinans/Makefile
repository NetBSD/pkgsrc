# $NetBSD: Makefile,v 1.16 2008/01/19 09:16:19 wiz Exp $
#

DISTNAME=		xfinans-5.9
PKGREVISION=		2
CATEGORIES=		finance x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/financial/accounting/}

MAINTAINER=		pkgsrc-users@NetBSD.org
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
	${RM} -f ${PREFIX}/${PKGMANDIR}/cat1/xfinans.0

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
