#
# New ports collection makefile for:	gnuplot
# Version required:			3.5
# Date Created:				30 January 1998
# Whom:					root@garbled.futureone.com
#
# $NetBSD: Makefile,v 1.1 1998/01/31 23:49:32 tron Exp $

DISTNAME=	gnuplot-3.5
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	root@garbled.futureone.com

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/gnuplot

MAN1=		man/man1/gnuplot.1

post-patch:
	${RM} ${WRKSRC}/docs/makefile

.include <bsd.port.mk>
