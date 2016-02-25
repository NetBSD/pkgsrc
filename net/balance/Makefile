# $NetBSD: Makefile,v 1.10 2016/02/25 16:20:50 jperkin Exp $
#

DISTNAME=	balance-3.57
CATEGORIES=	net
MASTER_SITES=	http://www.inlab.de/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	http://www.inlab.de/balance.html
COMMENT=	TCP loadbalancer with roundrobin and failover
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=	VARBASE
MAKE_ENV+=	VARBASE=${VARBASE}

MAKE_ENV.SunOS+=	LIBRARIES="-lsocket -lnsl"

OWN_DIRS_PERMS=	${VARBASE}/run/balance \
		${ROOT_USER} ${ROOT_GROUP} 0750

.include "../../mk/bsd.pkg.mk"
