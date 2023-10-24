# $NetBSD: buildlink3.mk,v 1.5 2023/10/24 22:10:32 wiz Exp $

BUILDLINK_TREE+=	rabbitmq-c

.if !defined(RABBITMQ_C_BUILDLINK3_MK)
RABBITMQ_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rabbitmq-c+=	rabbitmq-c>=0.6.0
BUILDLINK_ABI_DEPENDS.rabbitmq-c+=	rabbitmq-c>=0.13.0nb1
BUILDLINK_PKGSRCDIR.rabbitmq-c?=	../../net/rabbitmq-c

.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # RABBITMQ_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-rabbitmq-c
