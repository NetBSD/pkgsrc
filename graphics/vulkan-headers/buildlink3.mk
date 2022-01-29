# $NetBSD: buildlink3.mk,v 1.2 2022/01/29 22:07:27 triaxx Exp $

BUILDLINK_TREE+=	vulkan-headers

.if !defined(VULKAN_HEADERS_BUILDLINK3_MK)
VULKAN_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vulkan-headers+=	vulkan-headers>=1.1.126.0
BUILDLINK_PKGSRCDIR.vulkan-headers?=	../../graphics/vulkan-headers

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.endif	# VULKAN_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-vulkan-headers
