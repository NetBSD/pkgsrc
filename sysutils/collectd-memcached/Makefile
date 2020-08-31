# $NetBSD: Makefile,v 1.4 2020/08/31 18:11:25 wiz Exp $

COLLECTD_PACKAGE=	memcached
COLLECTD_PLUGINS=	memcachec memcached

COMMENT=		Statistics collection daemon - memcached plugins
PKGREVISION=		3

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libmemcached=${BUILDLINK_PREFIX.libmemcached}

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
