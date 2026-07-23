# $NetBSD: buildlink3.mk,v 1.2 2026/07/23 15:31:44 ryoon Exp $

BUILDLINK_TREE+=	libplacebo

.if !defined(LIBPLACEBO_BUILDLINK3_MK)
LIBPLACEBO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplacebo+=	libplacebo>=7.360.1
BUILDLINK_PKGSRCDIR.libplacebo?=	../../multimedia/libplacebo

.include "../../devel/xxhash/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.endif	# LIBPLACEBO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplacebo
