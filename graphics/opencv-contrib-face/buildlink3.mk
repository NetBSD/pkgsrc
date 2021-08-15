# $NetBSD: buildlink3.mk,v 1.3 2021/08/15 14:23:58 wiz Exp $

BUILDLINK_TREE+=	opencv-contrib-face

.if !defined(OPENCV_CONTRIB_FACE_BUILDLINK3_MK)
OPENCV_CONTRIB_FACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencv-contrib-face+=	opencv-contrib-face>=3.0.0
BUILDLINK_ABI_DEPENDS.opencv-contrib-face?=	opencv-contrib-face>=3.4.9nb2
BUILDLINK_PKGSRCDIR.opencv-contrib-face?=	../../graphics/opencv-contrib-face

.include "../../graphics/opencv/buildlink3.mk"
.endif	# OPENCV_CONTRIB_FACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencv-contrib-face
