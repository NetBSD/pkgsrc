# $NetBSD: Makefile,v 1.5 2019/08/11 13:23:04 wiz Exp $

COLLECTD_PACKAGE=	amqp

COMMENT=		Statistics collection daemon - amqp plugin
PKGREVISION=		2

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-librabbitmq=${BUILDLINK_PREFIX.rabbitmq-c}

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
