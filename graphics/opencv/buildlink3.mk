# $NetBSD: buildlink3.mk,v 1.16 2023/01/03 17:36:26 wiz Exp $

BUILDLINK_TREE+=	opencv

.if !defined(OPENCV_BUILDLINK3_MK)
OPENCV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencv+=	opencv>=3.0.0
BUILDLINK_ABI_DEPENDS.opencv+=	opencv>=3.4.16nb10
BUILDLINK_PKGSRCDIR.opencv?=	../../graphics/opencv

pkgbase := opencv
.include "../../mk/pkg-build-options.mk"

.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.opencv:Mjasper}
.  include "../../graphics/jasper/buildlink3.mk"
.endif
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif	# OPENCV_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencv
