# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:47 wiz Exp $

COLLECTD_PACKAGE=	redis
COLLECTD_PLUGINS=	redis write_redis

COMMENT=		Statistics collection daemon - redis plugins

.include "../../databases/hiredis/buildlink3.mk"
COLLECTD_LIB.hiredis=	${BUILDLINK_PREFIX.hiredis}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
