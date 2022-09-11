# $NetBSD: buildlink3.mk,v 1.7 2022/09/11 12:51:08 wiz Exp $

BUILDLINK_TREE+=	fna3d

.if !defined(FNA3D_BUILDLINK3_MK)
FNA3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fna3d+=	fna3d>=22.05
BUILDLINK_ABI_DEPENDS.fna3d?=	fna3d>=22.05nb2
BUILDLINK_PKGSRCDIR.fna3d?=	../../graphics/fna3d

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/mojoshader/buildlink3.mk"
.endif	# FNA3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-fna3d
