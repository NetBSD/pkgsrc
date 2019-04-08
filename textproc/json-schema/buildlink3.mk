# $NetBSD: buildlink3.mk,v 1.2 2019/04/08 22:07:42 wiz Exp $

BUILDLINK_TREE+=	json-schema

.if !defined(JSON_SCHEMA_BUILDLINK3_MK)
JSON_SCHEMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-schema+=	json-schema>=1.0
BUILDLINK_PKGSRCDIR.json-schema?=	../../textproc/json-schema
BUILDLINK_DEPMETHOD.json-schema?=	build

.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.endif	# JSON_SCHEMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-schema
