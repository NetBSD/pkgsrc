# $NetBSD: buildlink3.mk,v 1.7 2018/01/07 13:04:12 rillig Exp $

BUILDLINK_TREE+=	shapelib

.if !defined(SHAPELIB_BUILDLINK3_MK)
SHAPELIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shapelib+=	shapelib>=1.2.10
BUILDLINK_PKGSRCDIR.shapelib?=		../../geography/shapelib
.endif # SHAPELIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-shapelib
