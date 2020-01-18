# $NetBSD: Makefile,v 1.2 2020/01/18 21:50:59 jperkin Exp $

SYSLOG_MOD=		afamqp
SYSLOG_MOD_TARGET=	afamqp
COMMENT=		Syslog-ng RabbitMQ module
PKGREVISION=		1

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--enable-amqp
CONFIGURE_ARGS+=	--with-librabbitmq-client=system

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
