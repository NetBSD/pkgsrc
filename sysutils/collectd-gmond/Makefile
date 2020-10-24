# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:46 wiz Exp $

COLLECTD_PACKAGE=	gmond

COMMENT=		Statistics collection daemon - gmond plugin

.include "../../parallel/ganglia-monitor-core/buildlink3.mk"
COLLECTD_LIB.ganglia=	${BUILDLINK_PREFIX.ganglia-monitor-core}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
