# $NetBSD: Makefile,v 1.1 2016/08/21 20:20:27 fhajny Exp $

SYSLOG_MOD=		afamqp
SYSLOG_MOD_TARGET=	afamqp
COMMENT=		Syslog-ng RabbitMQ module

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--enable-amqp
CONFIGURE_ARGS+=	--with-librabbitmq-client=system

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
