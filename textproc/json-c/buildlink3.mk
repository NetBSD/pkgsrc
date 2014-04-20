# $NetBSD: buildlink3.mk,v 1.3 2014/04/20 00:09:04 ryoon Exp $

BUILDLINK_TREE+=	json-c

.if !defined(JSON_C_BUILDLINK3_MK)
JSON_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-c+=	json-c>=0.12
BUILDLINK_ABI_DEPENDS.json-c?=	json-c>=0.11
BUILDLINK_PKGSRCDIR.json-c?=	../../textproc/json-c
.endif	# JSON_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-c
