# $NetBSD: buildlink3.mk,v 1.1 2021/04/27 14:51:49 thor Exp $

BUILDLINK_TREE+=	vtk

.if !defined(VTK_BUILDLINK3_MK)
VTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vtk+=	vtk>=4.2
BUILDLINK_ABI_DEPENDS.vtk+=	vtk>=4.2
BUILDLINK_PKGSRCDIR.vtk?=	../../graphics/vtk

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.endif # VTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-vtk
