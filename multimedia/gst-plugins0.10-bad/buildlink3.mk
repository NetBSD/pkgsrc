# $NetBSD: buildlink3.mk,v 1.3 2006/07/08 23:11:01 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GST_PLUGINS0.10_BAD_BUILDLINK3_MK:=	${GST_PLUGINS0.10_BAD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins0.10-bad
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins0.10-bad}
BUILDLINK_PACKAGES+=	gst-plugins0.10-bad
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gst-plugins0.10-bad

.if !empty(GST_PLUGINS0.10_BAD_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gst-plugins0.10-bad+=	gst-plugins0.10-bad>=0.10.3
BUILDLINK_ABI_DEPENDS.gst-plugins0.10-bad?=	gst-plugins0.10-bad>=0.10.3
BUILDLINK_PKGSRCDIR.gst-plugins0.10-bad?= ../../multimedia/gst-plugins0.10-bad
.endif	# GST_PLUGINS0.10_BAD_BUILDLINK3_MK

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
