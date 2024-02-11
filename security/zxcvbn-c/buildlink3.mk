# $NetBSD: buildlink3.mk,v 1.1 2024/02/11 21:45:44 ryoon Exp $

BUILDLINK_TREE+=	zxcvbn-c

.if !defined(ZXCVBN_C_BUILDLINK3_MK)
ZXCVBN_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zxcvbn-c+=	zxcvbn-c>=2.5
BUILDLINK_PKGSRCDIR.zxcvbn-c?=		../../security/zxcvbn-c
.endif	# ZXCVBN_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-zxcvbn-c
