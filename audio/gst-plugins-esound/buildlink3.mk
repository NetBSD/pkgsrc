# $NetBSD: buildlink3.mk,v 1.2 2005/12/31 12:32:31 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GST_PLUGINS_ESOUND_BUILDLINK3_MK:=	${GST_PLUGINS_ESOUND_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins-esound
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins-esound}
BUILDLINK_PACKAGES+=	gst-plugins-esound

.if !empty(GST_PLUGINS_ESOUND_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gst-plugins-esound+=	gst-plugins-esound>=0.8.1
BUILDLINK_RECOMMENDED.gst-plugins-esound?=	gst-plugins-esound>=0.8.11nb1
BUILDLINK_PKGSRCDIR.gst-plugins-esound?=	../../audio/gst-plugins-esound
.endif	# GST_PLUGINS_ESOUND_BUILDLINK3_MK

.include "../../audio/esound/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
