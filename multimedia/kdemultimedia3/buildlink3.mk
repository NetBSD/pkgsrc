# $NetBSD: buildlink3.mk,v 1.3 2004/10/03 00:13:02 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KDEMULTIMEDIA_BUILDLINK3_MK:=	${KDEMULTIMEDIA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdemultimedia
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdemultimedia}
BUILDLINK_PACKAGES+=	kdemultimedia

.if !empty(KDEMULTIMEDIA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdemultimedia+=	kdemultimedia>=3.2.2
BUILDLINK_RECOMMENDED.kdemultimedia+=	kdemultimedia>=3.3.0nb1
BUILDLINK_PKGSRCDIR.kdemultimedia?=	../../multimedia/kdemultimedia3
.endif	# KDEMULTIMEDIA_BUILDLINK3_MK

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/tunepimp/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
