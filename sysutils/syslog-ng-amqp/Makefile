# $NetBSD: Makefile,v 1.6 2023/10/24 22:11:14 wiz Exp $

SYSLOG_MOD=		afamqp
SYSLOG_MOD_TARGET=	afamqp
COMMENT=		Syslog-ng RabbitMQ module
PKGREVISION=		1

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-amqp
CONFIGURE_ARGS+=	--with-librabbitmq-client=system

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
