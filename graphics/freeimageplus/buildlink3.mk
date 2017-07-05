# $NetBSD: buildlink3.mk,v 1.1 2017/07/05 08:46:26 nros Exp $

BUILDLINK_TREE+=	freeimageplus

.if !defined(FREEIMAGEPLUS_BUILDLINK3_MK)
FREEIMAGEPLUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freeimageplus+=	freeimageplus>=3.17.0
BUILDLINK_PKGSRCDIR.freeimageplus?=	../../graphics/freeimageplus

.include "../../graphics/freeimage/buildlink3.mk"
.endif	# FREEIMAGEPLUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-freeimageplus
