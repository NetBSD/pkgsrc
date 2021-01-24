# $NetBSD: buildlink3.mk,v 1.1 2021/01/24 19:03:47 maya Exp $

BUILDLINK_TREE+=	FNA3D

.if !defined(FNA3D_BUILDLINK3_MK)
FNA3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.FNA3D+=	FNA3D>=21.01
BUILDLINK_PKGSRCDIR.FNA3D?=	../../graphics/fna3d

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/mojoshader/buildlink3.mk"
.endif	# FNA3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-FNA3D
