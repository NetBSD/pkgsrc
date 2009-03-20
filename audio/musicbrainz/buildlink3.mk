# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:23:58 joerg Exp $

BUILDLINK_TREE+=	musicbrainz

.if !defined(MUSICBRAINZ_BUILDLINK3_MK)
MUSICBRAINZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.musicbrainz+=		musicbrainz>=2.0.2
BUILDLINK_ABI_DEPENDS.musicbrainz+=	musicbrainz>=2.1.2nb2
BUILDLINK_PKGSRCDIR.musicbrainz?=	../../audio/musicbrainz

.include "../../textproc/expat/buildlink3.mk"
.endif # MUSICBRAINZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-musicbrainz
