# $NetBSD: Makefile,v 1.1 2014/02/17 11:21:55 fhajny Exp $

COLLECTD_PACKAGE=	memcached
COLLECTD_PLUGINS=	memcachec memcached

COMMENT=		Statistics collection daemon - memcached plugins

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libmemcached=${BUILDLINK_PREFIX.libmemcached}

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
