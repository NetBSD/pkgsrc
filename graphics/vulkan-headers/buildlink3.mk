# $NetBSD: buildlink3.mk,v 1.1 2021/01/24 18:57:46 maya Exp $

BUILDLINK_TREE+=	vulkan-headers

.if !defined(VULKAN_HEADERS_BUILDLINK3_MK)
VULKAN_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vulkan-headers+=	vulkan-headers>=1.1.126.0
BUILDLINK_PKGSRCDIR.vulkan-headers?=	../../graphics/vulkan-headers
.endif	# VULKAN_HEADERS_BUILDLINK3_MK

.include "../../x11/liboldXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"

BUILDLINK_TREE+=	-vulkan-headers
