# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:35 joerg Exp $

BUILDLINK_TREE+=	shapelib

.if !defined(SHAPELIB_BUILDLINK3_MK)
SHAPELIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shapelib+=	shapelib>=1.2.10
BUILDLINK_PKGSRCDIR.shapelib?=	../../geography/shapelib
.endif # SHAPELIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-shapelib
