# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:46 wiz Exp $

COLLECTD_PACKAGE=	memcachec

COMMENT=		Statistics collection daemon - memcachec plugin

.include "../../devel/libmemcached/buildlink3.mk"
COLLECTD_LIB.memcached=	${BUILDLINK_PREFIX.libmemcached}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
