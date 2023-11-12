# $NetBSD: Makefile,v 1.30 2023/11/12 13:23:30 wiz Exp $

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins
PKGREVISION=		8

.include "../../databases/rrdtool/buildlink3.mk"
COLLECTD_LIB.rrd=	${BUILDLINK_PREFIX.rrdtool}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
