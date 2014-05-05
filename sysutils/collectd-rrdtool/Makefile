# $NetBSD: Makefile,v 1.2 2014/05/05 00:48:19 ryoon Exp $

PKGREVISION=		1

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-librrd=${BUILDLINK_PREFIX.rrdtool}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
