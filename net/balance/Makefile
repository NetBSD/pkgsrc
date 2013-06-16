# $NetBSD: Makefile,v 1.6 2013/06/16 08:09:11 ryoon Exp $
#

DISTNAME=	balance-3.54
CATEGORIES=	net
MASTER_SITES=	http://www.inlab.de/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inlab.de/balance.html
COMMENT=	TCP loadbalancer with roundrobin and failover
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=	VARBASE
MAKE_ENV+=	VARBASE=${VARBASE}

OWN_DIRS_PERMS=	${VARBASE}/run/balance \
		${ROOT_USER} ${ROOT_GROUP} 0750

.include "../../mk/bsd.pkg.mk"
