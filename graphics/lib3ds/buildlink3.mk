# $NetBSD: buildlink3.mk,v 1.12 2022/08/11 05:08:44 gutteridge Exp $

BUILDLINK_TREE+=	lib3ds

.if !defined(LIB3DS_BUILDLINK3_MK)
LIB3DS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lib3ds+=	lib3ds>=1.2.0nb2
BUILDLINK_ABI_DEPENDS.lib3ds+=	lib3ds>=1.2.0nb10
BUILDLINK_PKGSRCDIR.lib3ds?=	../../graphics/lib3ds

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif # LIB3DS_BUILDLINK3_MK

BUILDLINK_TREE+=	-lib3ds
