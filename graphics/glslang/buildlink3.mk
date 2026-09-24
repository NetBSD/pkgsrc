# $NetBSD: buildlink3.mk,v 1.2 2026/09/24 18:41:26 ktnb Exp $

BUILDLINK_TREE+=	glslang

.if !defined(GLSLANG_BUILDLINK3_MK)
GLSLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glslang+=	glslang>=1.4.341.0
BUILDLINK_ABI_DEPENDS.glslang+=	glslang>=1.4.341.0
BUILDLINK_PKGSRCDIR.glslang?=	../../graphics/glslang

.endif	# GLSLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-glslang
