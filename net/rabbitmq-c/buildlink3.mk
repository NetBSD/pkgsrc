# $NetBSD: buildlink3.mk,v 1.2 2015/04/07 08:57:32 fhajny Exp $

BUILDLINK_TREE+=	rabbitmq-c

.if !defined(RABBITMQ_C_BUILDLINK3_MK)
RABBITMQ_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rabbitmq-c+=	rabbitmq-c>=0.6.0
BUILDLINK_ABI_DEPENDS.rabbitmq-c+=	rabbitmq-c>=0.6.0
BUILDLINK_PKGSRCDIR.rabbitmq-c?=	../../net/rabbitmq-c

.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # RABBITMQ_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-rabbitmq-c
