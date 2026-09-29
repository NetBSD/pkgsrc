# $NetBSD: buildlink3.mk,v 1.16 2026/09/29 06:05:37 wiz Exp $

BUILDLINK_TREE+=	fna3d

.if !defined(FNA3D_BUILDLINK3_MK)
FNA3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fna3d+=	fna3d>=22.05
BUILDLINK_ABI_DEPENDS.fna3d?=	fna3d>=22.05nb11
BUILDLINK_PKGSRCDIR.fna3d?=	../../graphics/fna3d

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/mojoshader/buildlink3.mk"
.endif	# FNA3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-fna3d
