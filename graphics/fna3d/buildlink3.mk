# $NetBSD: buildlink3.mk,v 1.5 2022/05/15 12:08:07 tnn Exp $

BUILDLINK_TREE+=	fna3d

.if !defined(FNA3D_BUILDLINK3_MK)
FNA3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fna3d+=	fna3d>=22.05
BUILDLINK_PKGSRCDIR.fna3d?=	../../graphics/fna3d

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/mojoshader/buildlink3.mk"
.endif	# FNA3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-fna3d
