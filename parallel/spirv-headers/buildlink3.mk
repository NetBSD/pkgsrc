# $NetBSD: buildlink3.mk,v 1.3 2024/11/29 16:25:48 triaxx Exp $

BUILDLINK_TREE+=	spirv-headers

.if !defined(SPIRV_HEADERS_BUILDLINK3_MK)
SPIRV_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spirv-headers+=	spirv-headers>=1.3.216.0
BUILDLINK_PKGSRCDIR.spirv-headers?=	../../parallel/spirv-headers
BUILDLINK_DEPMETHOD.spirv-headers?=	build
.endif	# SPIRV_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-spirv-headers
