# $NetBSD: Makefile,v 1.39 2025/10/23 20:39:15 wiz Exp $

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins
PKGREVISION=		17

.include "../../databases/rrdtool/buildlink3.mk"
COLLECTD_LIB.rrd=	${BUILDLINK_PREFIX.rrdtool}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
