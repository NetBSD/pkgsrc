# $NetBSD: buildlink3.mk,v 1.3 2016/03/05 11:27:53 jperkin Exp $

BUILDLINK_TREE+=	rabbitmq-c

.if !defined(RABBITMQ_C_BUILDLINK3_MK)
RABBITMQ_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rabbitmq-c+=	rabbitmq-c>=0.6.0
BUILDLINK_ABI_DEPENDS.rabbitmq-c+=	rabbitmq-c>=0.7.1nb1
BUILDLINK_PKGSRCDIR.rabbitmq-c?=	../../net/rabbitmq-c

.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # RABBITMQ_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-rabbitmq-c
