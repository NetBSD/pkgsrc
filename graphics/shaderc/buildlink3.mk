# $NetBSD: buildlink3.mk,v 1.1 2026/08/26 10:59:43 adam Exp $

BUILDLINK_TREE+=	shaderc

.if !defined(SHADERC_BUILDLINK3_MK)
SHADERC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shaderc+=	shaderc>=2026.3nb1
BUILDLINK_PKGSRCDIR.shaderc?=	../../graphics/shaderc

.endif	# SHADERC_BUILDLINK3_MK

BUILDLINK_TREE+=	-shaderc
