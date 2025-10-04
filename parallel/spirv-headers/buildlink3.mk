# $NetBSD: buildlink3.mk,v 1.4 2025/10/04 12:07:45 tnn Exp $

BUILDLINK_TREE+=	spirv-headers

.if !defined(SPIRV_HEADERS_BUILDLINK3_MK)
SPIRV_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spirv-headers+=	spirv-headers>=1.4.321.0nb1
BUILDLINK_PKGSRCDIR.spirv-headers?=	../../parallel/spirv-headers
BUILDLINK_DEPMETHOD.spirv-headers?=	build
.endif	# SPIRV_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-spirv-headers
