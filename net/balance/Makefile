# $NetBSD: Makefile,v 1.11 2016/05/17 10:32:08 fhajny Exp $
#

DISTNAME=	balance-3.57
PKGREVISION=	1
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
		${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0750

.include "../../mk/bsd.pkg.mk"
