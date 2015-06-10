# $NetBSD: Makefile,v 1.5 2015/06/10 20:05:26 fhajny Exp $

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-librrd=${BUILDLINK_PREFIX.rrdtool}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
