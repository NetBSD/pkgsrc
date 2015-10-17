# $NetBSD: buildlink3.mk,v 1.1 2015/10/17 10:28:43 fhajny Exp $

BUILDLINK_TREE+=	opencv

.if !defined(OPENCV_BUILDLINK3_MK)
OPENCV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencv+=	opencv>=1.0.0nb3<3
BUILDLINK_PKGSRCDIR.opencv?=	../../graphics/opencv2

.endif	# OPENCV_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencv
