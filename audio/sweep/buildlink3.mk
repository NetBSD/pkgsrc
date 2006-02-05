# $NetBSD: buildlink3.mk,v 1.5 2006/02/05 23:08:14 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SWEEP_BUILDLINK3_MK:=	${SWEEP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sweep
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsweep}
BUILDLINK_PACKAGES+=	sweep

.if !empty(SWEEP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.sweep+=	sweep>=0.8.2nb6
BUILDLINK_RECOMMENDED.sweep+=	sweep>=0.8.3nb3
BUILDLINK_PKGSRCDIR.sweep?=	../../audio/sweep
.endif	# SWEEP_BUILDLINK3_MK

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
