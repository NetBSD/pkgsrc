# $NetBSD: buildlink3.mk,v 1.3 2004/02/09 23:56:32 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MUSICBRAINZ_BUILDLINK3_MK:=	${MUSICBRAINZ_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	musicbrainz
.endif

.if !empty(MUSICBRAINZ_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			musicbrainz
BUILDLINK_DEPENDS.musicbrainz+=		musicbrainz>=2.0.2
BUILDLINK_PKGSRCDIR.musicbrainz?=	../../audio/musicbrainz

.  include "../../devel/pkgconfig/buildlink3.mk"
.  include "../../textproc/expat/buildlink3.mk"
.endif # MUSICBRAINZ_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
