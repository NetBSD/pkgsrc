# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/06/20 19:25:49 agc Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gst-plugins-mad?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GST_PLUGINS_MAD_BUILDLINK3_MK:=	${GST_PLUGINS_MAD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins-mad
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins-mad}
BUILDLINK_PACKAGES+=	gst-plugins-mad

.if !empty(GST_PLUGINS_MAD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gst-plugins-mad+=	gst-plugins-mad>=0.8.1
BUILDLINK_PKGSRCDIR.gst-plugins-mad?=	../../multimedia/gst-plugins-mad
.endif	# GST_PLUGINS_MAD_BUILDLINK3_MK

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
