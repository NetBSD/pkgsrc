# $NetBSD: buildlink3.mk,v 1.1 2005/03/20 11:06:27 jmmv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GST_PLUGINS_GNOMEVFS_BUILDLINK3_MK:=	${GST_PLUGINS_GNOMEVFS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gst-plugins-gnomevfs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngst-plugins-gnomevfs}
BUILDLINK_PACKAGES+=	gst-plugins-gnomevfs

.if !empty(GST_PLUGINS_GNOMEVFS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gst-plugins-gnomevfs+=	gst-plugins-gnomevfs>=0.8.7
BUILDLINK_PKGSRCDIR.gst-plugins-gnomevfs?=	../../sysutils/gst-plugins-gnomevfs
.endif	# GST_PLUGINS_GNOMEVFS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
