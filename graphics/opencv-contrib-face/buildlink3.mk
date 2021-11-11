# $NetBSD: buildlink3.mk,v 1.5 2021/11/11 12:02:46 kim Exp $

BUILDLINK_TREE+=	opencv-contrib-face

.if !defined(OPENCV_CONTRIB_FACE_BUILDLINK3_MK)
OPENCV_CONTRIB_FACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencv-contrib-face+=	opencv-contrib-face>=3.0.0
BUILDLINK_ABI_DEPENDS.opencv-contrib-face?=	opencv-contrib-face>=3.4.16nb2
BUILDLINK_PKGSRCDIR.opencv-contrib-face?=	../../graphics/opencv-contrib-face

.include "../../graphics/opencv/buildlink3.mk"
.endif	# OPENCV_CONTRIB_FACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencv-contrib-face
