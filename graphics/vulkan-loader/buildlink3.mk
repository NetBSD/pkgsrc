# $NetBSD: buildlink3.mk,v 1.1 2026/04/13 13:56:07 kikadf Exp $

BUILDLINK_TREE+=	vulkan-loader

.if !defined(VULKAN_LOADER_BUILDLINK3_MK)
VULKAN_LOADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vulkan-loader+=	vulkan-loader>=1.4.341.0
BUILDLINK_PKGSRCDIR.vulkan-loader?=	../../graphics/vulkan-loader

.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.endif	# VULKAN_LOADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-vulkan-loader
