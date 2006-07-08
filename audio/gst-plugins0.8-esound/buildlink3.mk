# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:36 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GST_PLUGINS0.8_ESOUND_BUILDLINK3_MK:=	${GST_PLUGINS0.8_ESOUND_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins0.8-esound
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins0.8-esound}
BUILDLINK_PACKAGES+=	gst-plugins0.8-esound
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gst-plugins0.8-esound

.if !empty(GST_PLUGINS0.8_ESOUND_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gst-plugins0.8-esound+=	gst-plugins0.8-esound>=0.8.11
BUILDLINK_ABI_DEPENDS.gst-plugins0.8-esound?=	gst-plugins0.8-esound>=0.8.11nb5
BUILDLINK_PKGSRCDIR.gst-plugins0.8-esound?=	../../audio/gst-plugins0.8-esound
.endif	# GST_PLUGINS0.8_ESOUND_BUILDLINK3_MK

.include "../../audio/esound/buildlink3.mk"
.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
