# $NetBSD: Makefile,v 1.6 1998/09/13 19:35:06 garbled Exp $
#

DISTNAME=	gnuplot-3.5
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gnu.org/software/gnuplot/gnuplot.html

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/gnuplot

post-patch:
	${RM} ${WRKSRC}/docs/makefile

.include "../../mk/bsd.pkg.mk"
