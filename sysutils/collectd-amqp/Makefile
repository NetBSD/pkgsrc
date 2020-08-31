# $NetBSD: Makefile,v 1.7 2020/08/31 18:11:25 wiz Exp $

COLLECTD_PACKAGE=	amqp

COMMENT=		Statistics collection daemon - amqp plugin
PKGREVISION=		4

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-librabbitmq=${BUILDLINK_PREFIX.rabbitmq-c}

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
