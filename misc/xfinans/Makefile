# New ports collection makefile for:	Xfinans
# Version required:			5.9
# Date Created:				30 January 1998
# Whom:					root@garbled.futureone.com
#
# $NetBSD: Makefile,v 1.1 1998/02/08 23:48:39 hubertf Exp $
#

DISTNAME=		xfinans-5.9
WRKSRC=			${WRKDIR}/Xfinans/Src
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/financial/accounting

MAINTAINER=		root@garbled.futureone.com

RUN_DEPENDS=		gnuplot:${PORTSDIR}/graphics/gnuplot

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

.include <bsd.port.mk>
