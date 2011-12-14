# $NetBSD: buildlink3.mk,v 1.3 2011/12/14 11:55:20 fhajny Exp $

BUILDLINK_TREE+=			rabbitmq

.if !defined(RABBITMQ_BUILDLINK3_MK)
RABBITMQ_BUILDLINK3_MK:=

.include "version.mk"
RABBITMQ_PLUGINS=	lib/erlang/lib/rabbitmq_server-${RMQ_VERSION}/plugins

BUILDLINK_API_DEPENDS.rabbitmq+=	rabbitmq>=2.1.0
BUILDLINK_PKGSRCDIR.rabbitmq?=		../../net/rabbitmq

BUILDLINK_INCDIRS.rabbitmq?=		lib/erlang/lib/rabbitmq_server-${RMQ_VERSION}/include
.endif	# RABBITMQ_BUILDLINK3_MK

BUILDLINK_TREE+=			-rabbitmq
