# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:26 agc Exp $
#

DISTNAME=	gnuplot-3.5
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	root@garbled.futureone.com

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/gnuplot

MAN1=		gnuplot.1

post-patch:
	${RM} ${WRKSRC}/docs/makefile

.include "../../mk/bsd.pkg.mk"
