# $NetBSD: buildlink3.mk,v 1.4 2026/11/25 14:42:16 wiz Exp $

BUILDLINK_TREE+=	libplacebo

.if !defined(LIBPLACEBO_BUILDLINK3_MK)
LIBPLACEBO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplacebo+=	libplacebo>=7.360.1
BUILDLINK_ABI_DEPENDS.libplacebo+=	libplacebo>=7.387.0
BUILDLINK_PKGSRCDIR.libplacebo?=	../../multimedia/libplacebo

.include "../../devel/xxhash/buildlink3.mk"
.include "../../mk/mesa.buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.endif	# LIBPLACEBO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplacebo
