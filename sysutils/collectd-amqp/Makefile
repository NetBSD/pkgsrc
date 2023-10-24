# $NetBSD: Makefile,v 1.9 2023/10/24 22:11:05 wiz Exp $

COLLECTD_PACKAGE=	amqp

COMMENT=		Statistics collection daemon - amqp plugin
PKGREVISION=		1

.include "../../net/rabbitmq-c/buildlink3.mk"
COLLECTD_LIB.rabbitmq=	${BUILDLINK_PREFIX.rabbitmq-c}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
