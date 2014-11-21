# $NetBSD: buildlink3.mk,v 1.11 2014/11/21 23:22:17 mef Exp $

BUILDLINK_TREE+=	libmusicbrainz

.if !defined(LIBMUSICBRAINZ_BUILDLINK3_MK)
LIBMUSICBRAINZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmusicbrainz+=	libmusicbrainz>=3.0.0
BUILDLINK_ABI_DEPENDS.libmusicbrainz+=	libmusicbrainz>=3.0.3nb4
BUILDLINK_PKGSRCDIR.libmusicbrainz?=	../../audio/libmusicbrainz

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.endif # LIBMUSICBRAINZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusicbrainz
