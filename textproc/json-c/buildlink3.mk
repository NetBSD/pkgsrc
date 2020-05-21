# $NetBSD: buildlink3.mk,v 1.5 2020/05/21 10:38:14 nia Exp $

BUILDLINK_TREE+=	json-c

.if !defined(JSON_C_BUILDLINK3_MK)
JSON_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-c+=	json-c>=0.14
BUILDLINK_ABI_DEPENDS.json-c+=	json-c>=0.14
BUILDLINK_PKGSRCDIR.json-c?=	../../textproc/json-c
.endif	# JSON_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-c
