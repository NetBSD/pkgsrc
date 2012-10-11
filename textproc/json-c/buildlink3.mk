# $NetBSD: buildlink3.mk,v 1.1 2012/10/11 15:40:40 ryoon Exp $

BUILDLINK_TREE+=	json-c

.if !defined(JSON_C_BUILDLINK3_MK)
JSON_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-c+=	json-c>=0.10
BUILDLINK_PKGSRCDIR.json-c?=	../../textproc/json-c
.endif	# JSON_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-c
