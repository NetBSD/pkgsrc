# $NetBSD: Makefile,v 1.3 2021/09/16 09:22:47 wiz Exp $

SYSLOG_MOD=		afamqp
SYSLOG_MOD_TARGET=	afamqp
COMMENT=		Syslog-ng RabbitMQ module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-amqp
CONFIGURE_ARGS+=	--with-librabbitmq-client=system

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
