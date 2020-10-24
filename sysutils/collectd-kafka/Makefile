# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:46 wiz Exp $

COLLECTD_PACKAGE=	kafka
COLLECTD_PLUGINS=	write_kafka

COMMENT=		Statistics collection daemon - write_kafka plugin

.include "../../devel/librdkafka/buildlink3.mk"
COLLECTD_LIB.rdkafka=	${BUILDLINK_PREFIX.librdkafka}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
