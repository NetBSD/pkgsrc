# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:41 joerg Exp $

BUILDLINK_TREE+=	lib3ds

.if !defined(LIB3DS_BUILDLINK3_MK)
LIB3DS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lib3ds+=	lib3ds>=1.2.0nb2
BUILDLINK_ABI_DEPENDS.lib3ds?=	lib3ds>=1.2.0nb4
BUILDLINK_PKGSRCDIR.lib3ds?=	../../graphics/lib3ds

.include "../../graphics/Mesa/buildlink3.mk"
.endif # LIB3DS_BUILDLINK3_MK

BUILDLINK_TREE+=	-lib3ds
