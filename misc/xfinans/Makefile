# $NetBSD: Makefile,v 1.9 1999/02/09 16:08:59 bad Exp $
#

DISTNAME=		xfinans-5.9
WRKSRC=			${WRKDIR}/Xfinans/Src
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/financial/accounting

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.cs.auc.dk/~lupus/xfinans.html

DEPENDS=		gnuplot-3.7:../../graphics/gnuplot

USE_IMAKE=		yes

post-patch:
	${TOUCH} ${WRKSRC}/xfinans.man

post-install:
	${MKDIR} ${PREFIX}/share/examples/Xfinans
	${MKDIR} ${PREFIX}/share/doc/Xfinans
	${CP} ${WRKSRC}/../XFinans.defaults ${PREFIX}/lib/X11/app-defaults/XFinans
	${CP} ${WRKSRC}/../*.acc ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/../xfin.ps ${PREFIX}/share/doc/Xfinans
	${CP} ${WRKSRC}/../README ${PREFIX}/share/doc/Xfinans
	${CP} ${WRKSRC}/../INSTALL ${PREFIX}/share/doc/Xfinans
	${CP} ${WRKSRC}/../hyperhelp ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/../hyperhelp.index ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/../finans.bkd ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/../variables ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/../categories ${PREFIX}/share/examples/Xfinans
	${CP} ${WRKSRC}/../category_engine ${PREFIX}/share/examples/Xfinans
	${RM} ${PREFIX}/man/cat1/xfinans.0

.include "../../mk/bsd.pkg.mk"
