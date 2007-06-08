# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/08 07:02:15 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMUSICBRAINZ_BUILDLINK3_MK:=	${LIBMUSICBRAINZ_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libmusicbrainz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmusicbrainz}
BUILDLINK_PACKAGES+=	libmusicbrainz
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libmusicbrainz

.if ${LIBMUSICBRAINZ_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libmusicbrainz+=	libmusicbrainz>=3.0.0
BUILDLINK_PKGSRCDIR.libmusicbrainz?=	../../zzz/libmusicbrainz
.endif	# LIBMUSICBRAINZ_BUILDLINK3_MK

.include "../../www/neon/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
