# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/14 11:10:01 obache Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CLUTTER_GST_BUILDLINK3_MK:=	${CLUTTER_GST_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	clutter-gst
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nclutter-gst}
BUILDLINK_PACKAGES+=	clutter-gst
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}clutter-gst

.if ${CLUTTER_GST_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.clutter-gst+=	clutter-gst>=0.8.0
BUILDLINK_PKGSRCDIR.clutter-gst?=	../../multimedia/clutter-gst
.endif	# CLUTTER_GST_BUILDLINK3_MK

.include "../../graphics/clutter/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
