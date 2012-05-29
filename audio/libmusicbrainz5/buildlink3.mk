# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/29 13:31:38 wiz Exp $

BUILDLINK_TREE+=	libmusicbrainz5

.if !defined(LIBMUSICBRAINZ5_BUILDLINK3_MK)
LIBMUSICBRAINZ5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmusicbrainz5+=	libmusicbrainz5>=5.0.1
BUILDLINK_PKGSRCDIR.libmusicbrainz5?=	../../audio/libmusicbrainz5

.include "../../www/neon/buildlink3.mk"
.endif	# LIBMUSICBRAINZ5_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusicbrainz5
