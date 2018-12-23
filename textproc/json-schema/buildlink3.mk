# $NetBSD: buildlink3.mk,v 1.1 2018/12/23 17:22:21 wiz Exp $

BUILDLINK_TREE+=	json-schema

.if !defined(JSON_SCHEMA_BUILDLINK3_MK)
JSON_SCHEMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-schema+=	json-schema>=1.0
BUILDLINK_PKGSRCDIR.json-schema?=	../../textproc/json-schema
BUILDLINK_DEPMETHOD.json-schema?=	build

.include "../../textproc/jsoncpp/buildlink3.mk"
.endif	# JSON_SCHEMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-schema
