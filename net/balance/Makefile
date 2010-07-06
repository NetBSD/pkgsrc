# $NetBSD: Makefile,v 1.4 2010/07/06 10:17:14 jmmv Exp $
#

DISTNAME=	balance-3.15
CATEGORIES=	net
MASTER_SITES=	http://www.inlab.de/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inlab.de/balance.html
COMMENT=	TCP loadbalancer with roundrobin and failover

BUILD_TARGET=	balance

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/balance ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/balance.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
