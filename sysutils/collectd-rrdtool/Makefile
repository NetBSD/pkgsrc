# $NetBSD: Makefile,v 1.26 2022/11/23 16:21:04 adam Exp $

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins
PKGREVISION=		4

.include "../../databases/rrdtool/buildlink3.mk"
COLLECTD_LIB.rrd=	${BUILDLINK_PREFIX.rrdtool}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
