# $NetBSD: Makefile,v 1.6 2020/01/18 21:50:52 jperkin Exp $

COLLECTD_PACKAGE=	amqp

COMMENT=		Statistics collection daemon - amqp plugin
PKGREVISION=		3

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-librabbitmq=${BUILDLINK_PREFIX.rabbitmq-c}

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
