# $NetBSD: buildlink3.mk,v 1.1 2004/06/20 20:32:54 agc Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GST_PLUGINS_MAD_BUILDLINK3_MK:=	${GST_PLUGINS_MAD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins-mad
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins-mad}
BUILDLINK_PACKAGES+=	gst-plugins-mad

.if !empty(GST_PLUGINS_MAD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gst-plugins-mad+=	gst-plugins-mad>=0.8.1
BUILDLINK_PKGSRCDIR.gst-plugins-mad?=	../../audio/gst-plugins-mad
.endif	# GST_PLUGINS_MAD_BUILDLINK3_MK

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
