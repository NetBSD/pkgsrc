# $NetBSD: Makefile,v 1.2 2007/01/07 09:14:02 rillig Exp $
#

DISTNAME=	balance-3.15
CATEGORIES=	net
MASTER_SITES=	http://www.inlab.de/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.inlab.de/balance.html
COMMENT=	TCP loadbalancer with roundrobin and failover

BUILD_TARGET=	balance

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/balance ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/balance.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
