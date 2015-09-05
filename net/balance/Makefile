# $NetBSD: Makefile,v 1.9 2015/09/05 16:16:03 wiedi Exp $
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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LIBRARIES="-lsocket -lnsl"
.endif

OWN_DIRS_PERMS=	${VARBASE}/run/balance \
		${ROOT_USER} ${ROOT_GROUP} 0750

.include "../../mk/bsd.pkg.mk"
