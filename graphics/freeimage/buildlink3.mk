# $NetBSD: buildlink3.mk,v 1.1 2015/02/12 22:40:05 snj Exp $

BUILDLINK_TREE+=	freeimage

.if !defined(FREEIMAGE_BUILDLINK3_MK)
FREEIMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freeimage+=	freeimage>=3.16.0
BUILDLINK_PKGSRCDIR.freeimage?=	../../graphics/freeimage
.endif	# FREEIMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-freeimage
