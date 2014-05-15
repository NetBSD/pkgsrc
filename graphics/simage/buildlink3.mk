# $NetBSD: buildlink3.mk,v 1.22 2014/05/15 14:41:53 adam Exp $

BUILDLINK_TREE+=	simage

.if !defined(SIMAGE_BUILDLINK3_MK)
SIMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.simage+=	simage>=1.6.1
BUILDLINK_ABI_DEPENDS.simage+=	simage>=1.7.0nb2
BUILDLINK_PKGSRCDIR.simage?=	../../graphics/simage

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif # SIMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-simage
