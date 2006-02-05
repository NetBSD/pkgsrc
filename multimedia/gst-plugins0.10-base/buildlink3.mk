# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:10:15 joerg Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GST_PLUGINS0.10_BASE_BUILDLINK3_MK:=	${GST_PLUGINS0.10_BASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins0.10-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins0.10-base}
BUILDLINK_PACKAGES+=	gst-plugins0.10-base

.if !empty(GST_PLUGINS0.10_BASE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.1
BUILDLINK_RECOMMENDED.gst-plugins0.10-base?=	gst-plugins0.10-base>=0.10.2nb1
BUILDLINK_PKGSRCDIR.gst-plugins0.10-base?=	../../multimedia/gst-plugins0.10-base
.endif	# GST_PLUGINS0.10_BASE_BUILDLINK3_MK

.include "../../multimedia/gstreamer0.10/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
