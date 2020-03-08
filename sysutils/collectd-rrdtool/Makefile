# $NetBSD: Makefile,v 1.15 2020/03/08 16:51:15 wiz Exp $

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins
PKGREVISION=		7

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-librrd=${BUILDLINK_PREFIX.rrdtool}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
