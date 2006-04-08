# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/08 11:42:37 jmmv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GST_PLUGINS0.10_UGLY_BUILDLINK3_MK:=	${GST_PLUGINS0.10_UGLY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins0.10-ugly
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins0.10-ugly}
BUILDLINK_PACKAGES+=	gst-plugins0.10-ugly

.if !empty(GST_PLUGINS0.10_UGLY_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gst-plugins0.10-ugly+=	gst-plugins0.10-ugly>=0.10.3
BUILDLINK_ABI_DEPENDS.gst-plugins0.10-ugly?=	gst-plugins0.10-ugly>=0.10.3
BUILDLINK_PKGSRCDIR.gst-plugins0.10-ugly?=	../../multimedia/gst-plugins0.10-ugly
.endif	# GST_PLUGINS0.10_UGLY_BUILDLINK3_MK

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
