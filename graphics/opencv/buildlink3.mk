# $NetBSD: buildlink3.mk,v 1.2 2015/10/08 17:45:59 fhajny Exp $

BUILDLINK_TREE+=	opencv

.if !defined(OPENCV_BUILDLINK3_MK)
OPENCV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencv+=	opencv>=3.0.0
BUILDLINK_PKGSRCDIR.opencv?=	../../graphics/opencv

.endif	# OPENCV_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencv
