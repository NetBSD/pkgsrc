# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:32:27 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GST_PLUGINS0.8_BUILDLINK3_MK:=	${GST_PLUGINS0.8_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins0.8
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins0.8}
BUILDLINK_PACKAGES+=	gst-plugins0.8

.if !empty(GST_PLUGINS0.8_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gst-plugins0.8+=	gst-plugins0.8>=0.8.11
BUILDLINK_RECOMMENDED.gst-plugins0.8?=	gst-plugins0.8>=0.8.11
BUILDLINK_PKGSRCDIR.gst-plugins0.8?=	../../multimedia/gst-plugins0.8
.endif	# GST_PLUGINS0.8_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
