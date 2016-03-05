# $NetBSD: Makefile,v 1.2 2016/03/05 11:29:28 jperkin Exp $

COLLECTD_PACKAGE=	amqp

COMMENT=		Statistics collection daemon - amqp plugin
PKGREVISION=		1

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-librabbitmq=${BUILDLINK_PREFIX.rabbitmq-c}

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
