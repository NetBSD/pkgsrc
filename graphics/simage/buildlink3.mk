# $NetBSD: buildlink3.mk,v 1.5 2006/04/06 06:22:05 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SIMAGE_BUILDLINK3_MK:=	${SIMAGE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	simage
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsimage}
BUILDLINK_PACKAGES+=	simage

.if !empty(SIMAGE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.simage+=	simage>=1.6.1
BUILDLINK_ABI_DEPENDS.simage+=	simage>=1.6.1nb2
BUILDLINK_PKGSRCDIR.simage?=	../../graphics/simage
.endif	# SIMAGE_BUILDLINK3_MK

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
