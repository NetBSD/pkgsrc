# $NetBSD: buildlink3.mk,v 1.2 2013/11/25 11:59:08 wiz Exp $

BUILDLINK_TREE+=	json-c

.if !defined(JSON_C_BUILDLINK3_MK)
JSON_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-c+=	json-c>=0.10
BUILDLINK_ABI_DEPENDS.json-c?=	json-c>=0.11
BUILDLINK_PKGSRCDIR.json-c?=	../../textproc/json-c
.endif	# JSON_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-c
