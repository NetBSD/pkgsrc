# $NetBSD: buildlink3.mk,v 1.1 2008/11/06 14:21:10 obache Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
P5_GSTREAMER_BUILDLINK3_MK:=	${P5_GSTREAMER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	p5-GStreamer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Np5-GStreamer}
BUILDLINK_PACKAGES+=	p5-GStreamer
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}p5-GStreamer

.if ${P5_GSTREAMER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.p5-GStreamer+=	p5-GStreamer>=0.11
BUILDLINK_PKGSRCDIR.p5-GStreamer?=	../../multimedia/p5-GStreamer
.endif	# P5_GSTREAMER_BUILDLINK3_MK

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
