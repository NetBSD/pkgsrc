# $NetBSD: buildlink3.mk,v 1.20 2023/11/08 13:18:07 wiz Exp $

BUILDLINK_TREE+=	libmusicbrainz5

.if !defined(LIBMUSICBRAINZ5_BUILDLINK3_MK)
LIBMUSICBRAINZ5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmusicbrainz5+=	libmusicbrainz5>=5.0.1
BUILDLINK_ABI_DEPENDS.libmusicbrainz5?=	libmusicbrainz5>=5.1.0nb14
BUILDLINK_PKGSRCDIR.libmusicbrainz5?=	../../audio/libmusicbrainz5

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.endif	# LIBMUSICBRAINZ5_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusicbrainz5
