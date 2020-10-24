# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:49 wiz Exp $

COLLECTD_PACKAGE=	yajl
COLLECTD_PLUGINS=	ceph log_logstash sysevent

COMMENT=		Statistics collection daemon - YAJL-based plugins

.include "../../devel/yajl/buildlink3.mk"
COLLECTD_LIB.yajl=	${BUILDLINK_PREFIX.yajl}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
