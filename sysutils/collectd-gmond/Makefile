# $NetBSD: Makefile,v 1.2 2022/12/15 10:38:08 jperkin Exp $

COLLECTD_PACKAGE=	gmond

COMMENT=		Statistics collection daemon - gmond plugin

.include "../../parallel/ganglia-monitor-core/buildlink3.mk"
COLLECTD_LIB.ganglia=	${BUILDLINK_PREFIX.ganglia-monitor-core}

.include "../../sysutils/collectd/Makefile.common"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
