# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 11:39:24 wiz Exp $
#
# This Makefile fragment is included by packages that use sweep.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SWEEP_BUILDLINK3_MK:=	${SWEEP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sweep
.endif

.if !empty(SWEEP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			sweep
BUILDLINK_DEPENDS.sweep+=		sweep>=0.8.2nb6
BUILDLINK_PKGSRCDIR.sweep?=		../../audio/sweep

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.endif # SWEEP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
