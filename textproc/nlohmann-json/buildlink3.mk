# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 20:18:21 nikita Exp $

BUILDLINK_TREE+=	nlohmann-json

.if !defined(NLOHMANN_JSON_BUILDLINK3_MK)
NLOHMANN_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nlohmann-json+=	nlohmann-json>=3.7.0
BUILDLINK_DEPMETHOD.nlohmann-json?=	build
BUILDLINK_PKGSRCDIR.nlohmann-json?=	../../textproc/nlohmann-json
.endif	# NLOHMANN_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-nlohmann-json
