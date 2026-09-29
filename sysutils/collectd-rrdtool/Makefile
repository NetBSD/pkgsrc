# $NetBSD: Makefile,v 1.44 2026/09/29 06:07:31 wiz Exp $

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins
PKGREVISION=		22

.include "../../databases/rrdtool/buildlink3.mk"
COLLECTD_LIB.rrd=	${BUILDLINK_PREFIX.rrdtool}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
