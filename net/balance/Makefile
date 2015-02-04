# $NetBSD: Makefile,v 1.8 2015/02/04 01:52:41 mef Exp $
#

DISTNAME=	balance-3.56
CATEGORIES=	net
MASTER_SITES=	http://www.inlab.de/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
