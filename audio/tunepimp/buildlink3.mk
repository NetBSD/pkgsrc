# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/08/21 11:17:55 markd Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TUNEPIMP_BUILDLINK3_MK:=	${TUNEPIMP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tunepimp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntunepimp}
BUILDLINK_PACKAGES+=	tunepimp

.if !empty(TUNEPIMP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tunepimp+=	tunepimp>=0.3.0
BUILDLINK_PKGSRCDIR.tunepimp?=	../../audio/tunepimp
.endif	# TUNEPIMP_BUILDLINK3_MK

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
