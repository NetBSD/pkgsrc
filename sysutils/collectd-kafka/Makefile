# $NetBSD: Makefile,v 1.2 2023/10/24 22:11:05 wiz Exp $

COLLECTD_PACKAGE=	kafka
COLLECTD_PLUGINS=	write_kafka

COMMENT=		Statistics collection daemon - write_kafka plugin
PKGREVISION=		1

.include "../../devel/librdkafka/buildlink3.mk"
COLLECTD_LIB.rdkafka=	${BUILDLINK_PREFIX.librdkafka}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
