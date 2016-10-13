# $NetBSD: Makefile,v 1.3 2016/10/13 15:17:28 fhajny Exp $

COLLECTD_PACKAGE=	amqp

COMMENT=		Statistics collection daemon - amqp plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-librabbitmq=${BUILDLINK_PREFIX.rabbitmq-c}

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
