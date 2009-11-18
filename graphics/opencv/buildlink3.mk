# $NetBSD: buildlink3.mk,v 1.1 2009/11/18 23:08:48 wiz Exp $

BUILDLINK_TREE+=	opencv

.if !defined(OPENCV_BUILDLINK3_MK)
OPENCV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencv+=	opencv>=1.0.0nb3
BUILDLINK_PKGSRCDIR.opencv?=	../../graphics/opencv

.endif	# OPENCV_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencv
