# $NetBSD: Makefile,v 1.20 2012/10/03 16:10:14 asau Exp $
#

DISTNAME=		xfinans-5.9
PKGREVISION=		4
CATEGORIES=		finance x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/financial/accounting/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.io.com/~acroyear/xfinans/
COMMENT=		Xfinans is a useful financial tracking, and account balancing tool

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot

WRKSRC=			${WRKDIR}/Xfinans
CONFIGURE_DIRS=		Src
USE_IMAKE=		yes

INSTALLATION_DIRS=	lib/X11/app-defaults/XFinans \
			share/doc/Xfinans share/examples/Xfinans

post-install:
	${INSTALL_DATA} ${WRKSRC}/XFinans.defaults ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XFinans
	${INSTALL_DATA} ${WRKSRC}/*.acc ${DESTDIR}${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/xfin.ps ${DESTDIR}${PREFIX}/share/doc/Xfinans
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/Xfinans
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/Xfinans
	${INSTALL_DATA} ${WRKSRC}/hyperhelp ${DESTDIR}${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/hyperhelp.index ${DESTDIR}${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/finans.bkd ${DESTDIR}${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/variables ${DESTDIR}${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/categories ${DESTDIR}${PREFIX}/share/examples/Xfinans
	${INSTALL_DATA} ${WRKSRC}/category_engine ${DESTDIR}${PREFIX}/share/examples/Xfinans
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/xfinans.0

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
