# $NetBSD: buildlink3.mk,v 1.4 2004/02/19 17:54:05 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MUSICBRAINZ_BUILDLINK3_MK:=	${MUSICBRAINZ_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	musicbrainz
.endif

.if !empty(MUSICBRAINZ_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			musicbrainz
BUILDLINK_DEPENDS.musicbrainz+=		musicbrainz>=2.0.2
BUILDLINK_PKGSRCDIR.musicbrainz?=	../../audio/musicbrainz

.  include "../../textproc/expat/buildlink3.mk"
.endif # MUSICBRAINZ_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
