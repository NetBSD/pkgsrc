# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:36:11 wiz Exp $

BUILDLINK_TREE+=	json-schema

.if !defined(JSON_SCHEMA_BUILDLINK3_MK)
JSON_SCHEMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-schema+=	json-schema>=1.0
BUILDLINK_ABI_DEPENDS.json-schema?=	json-schema>=1.3nb3
BUILDLINK_PKGSRCDIR.json-schema?=	../../textproc/json-schema
BUILDLINK_DEPMETHOD.json-schema?=	build

.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.endif	# JSON_SCHEMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-schema
