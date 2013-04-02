# $NetBSD: buildlink3.mk,v 1.4 2013/04/02 10:40:36 fhajny Exp $

BUILDLINK_TREE+=			rabbitmq

.if !defined(RABBITMQ_BUILDLINK3_MK)
RABBITMQ_BUILDLINK3_MK:=

.include "version.mk"
BUILDLINK_API_DEPENDS.rabbitmq+=	rabbitmq>=2.1.0
BUILDLINK_PKGSRCDIR.rabbitmq?=		../../net/rabbitmq

BUILDLINK_INCDIRS.rabbitmq?=		lib/erlang/lib/rabbitmq_server-${RMQ_VERSION}/include
.endif	# RABBITMQ_BUILDLINK3_MK

BUILDLINK_TREE+=			-rabbitmq
