# $NetBSD: Makefile,v 1.5 1998/08/20 15:17:01 tsarna Exp $
#

DISTNAME=	gnuplot-3.5
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	root@garbled.futureone.com
HOMEPAGE=	http://www.gnu.org/software/gnuplot/gnuplot.html

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/gnuplot

post-patch:
	${RM} ${WRKSRC}/docs/makefile

.include "../../mk/bsd.pkg.mk"
