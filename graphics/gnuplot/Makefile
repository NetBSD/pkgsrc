# $NetBSD: Makefile,v 1.4 1998/06/22 12:39:46 agc Exp $
#

DISTNAME=	gnuplot-3.5
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	root@garbled.futureone.com

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/gnuplot

post-patch:
	${RM} ${WRKSRC}/docs/makefile

.include "../../mk/bsd.pkg.mk"
