# $NetBSD: Makefile,v 1.27 2023/01/29 21:17:44 ryoon Exp $

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins
PKGREVISION=		5

.include "../../databases/rrdtool/buildlink3.mk"
COLLECTD_LIB.rrd=	${BUILDLINK_PREFIX.rrdtool}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
