# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:31:54 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GST_PLUGINS0.8_ARTSD_BUILDLINK3_MK:=	${GST_PLUGINS0.8_ARTSD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins0.8-artsd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins0.8-artsd}
BUILDLINK_PACKAGES+=	gst-plugins0.8-artsd

.if !empty(GST_PLUGINS0.8_ARTSD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gst-plugins0.8-artsd+=	gst-plugins0.8-artsd>=0.8.11
BUILDLINK_RECOMMENDED.gst-plugins0.8-artsd?=	gst-plugins0.8-artsd>=0.8.11
BUILDLINK_PKGSRCDIR.gst-plugins0.8-artsd?=	../../audio/gst-plugins0.8-artsd
.endif	# GST_PLUGINS0.8_ARTSD_BUILDLINK3_MK

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
