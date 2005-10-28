# $NetBSD: Makefile,v 1.1.1.1 2005/10/28 20:46:26 minskim Exp $
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
	${INSTALL_MAN} ${WRKSRC}/balance.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
