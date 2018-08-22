# $NetBSD: Makefile,v 1.2 2018/08/22 09:46:32 wiz Exp $

COLLECTD_PACKAGE=	memcached
COLLECTD_PLUGINS=	memcachec memcached

COMMENT=		Statistics collection daemon - memcached plugins
PKGREVISION=		1

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libmemcached=${BUILDLINK_PREFIX.libmemcached}

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
