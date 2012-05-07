# $NetBSD: buildlink3.mk,v 1.8 2012/05/07 01:53:14 dholland Exp $

BUILDLINK_TREE+=	libmusicbrainz

.if !defined(LIBMUSICBRAINZ_BUILDLINK3_MK)
LIBMUSICBRAINZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmusicbrainz+=	libmusicbrainz>=3.0.0
BUILDLINK_ABI_DEPENDS.libmusicbrainz+=	libmusicbrainz>=3.0.2nb1
BUILDLINK_PKGSRCDIR.libmusicbrainz?=	../../audio/libmusicbrainz

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.endif # LIBMUSICBRAINZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusicbrainz
