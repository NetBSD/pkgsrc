# $NetBSD: Makefile,v 1.4 2021/12/08 16:06:37 adam Exp $

SYSLOG_MOD=		afamqp
SYSLOG_MOD_TARGET=	afamqp
COMMENT=		Syslog-ng RabbitMQ module
PKGREVISION=		1

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-amqp
CONFIGURE_ARGS+=	--with-librabbitmq-client=system

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
