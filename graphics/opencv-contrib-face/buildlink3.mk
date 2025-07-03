# $NetBSD: buildlink3.mk,v 1.26 2025/07/03 06:28:32 wiz Exp $

BUILDLINK_TREE+=	opencv-contrib-face

.if !defined(OPENCV_CONTRIB_FACE_BUILDLINK3_MK)
OPENCV_CONTRIB_FACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencv-contrib-face+=	opencv-contrib-face>=3.0.0
BUILDLINK_ABI_DEPENDS.opencv-contrib-face?=	opencv-contrib-face>=4.11.0nb3
BUILDLINK_PKGSRCDIR.opencv-contrib-face?=	../../graphics/opencv-contrib-face

.include "../../graphics/opencv/buildlink3.mk"
.endif	# OPENCV_CONTRIB_FACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencv-contrib-face
