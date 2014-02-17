# $NetBSD: Makefile,v 1.1 2014/02/17 11:21:55 fhajny Exp $

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-librrd=${BUILDLINK_PREFIX.rrdtool}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
