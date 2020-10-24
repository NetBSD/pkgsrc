# $NetBSD: Makefile,v 1.8 2020/10/24 22:39:45 wiz Exp $

COLLECTD_PACKAGE=	amqp

COMMENT=		Statistics collection daemon - amqp plugin

.include "../../net/rabbitmq-c/buildlink3.mk"
COLLECTD_LIB.rabbitmq=	${BUILDLINK_PREFIX.rabbitmq-c}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
