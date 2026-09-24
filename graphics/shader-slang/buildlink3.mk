# $NetBSD: buildlink3.mk,v 1.1 2026/09/24 18:41:26 ktnb Exp $

BUILDLINK_TREE+=	shader-slang

.if !defined(SHADER_SLANG_BUILDLINK3_MK)
SHADER_SLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shader-slang+=	shader-slang>=2026.18
BUILDLINK_PKGSRCDIR.shader-slang?=	../../graphics/shader-slang

.endif	# SHADER_SLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-shader-slang
