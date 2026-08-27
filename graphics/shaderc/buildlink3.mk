# $NetBSD: buildlink3.mk,v 1.2 2026/08/27 11:17:18 adam Exp $

BUILDLINK_TREE+=	shaderc

.if !defined(SHADERC_BUILDLINK3_MK)
SHADERC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shaderc+=	shaderc>=2026.3nb1
BUILDLINK_PKGSRCDIR.shaderc?=	../../graphics/shaderc

.include "../../graphics/glslang/buildlink3.mk"
.include "../../parallel/spirv-tools/buildlink3.mk"
.endif	# SHADERC_BUILDLINK3_MK

BUILDLINK_TREE+=	-shaderc
