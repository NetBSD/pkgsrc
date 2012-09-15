# $NetBSD: buildlink3.mk,v 1.8 2012/09/15 10:03:37 obache Exp $

BUILDLINK_TREE+=	gst-buzztard

.if !defined(GST_BUZZTARD_BUILDLINK3_MK)
GST_BUZZTARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-buzztard+=	gst-buzztard>=0.5.0
BUILDLINK_ABI_DEPENDS.gst-buzztard+=	gst-buzztard>=0.5.0nb6
BUILDLINK_PKGSRCDIR.gst-buzztard?=	../../audio/gst-buzztard

.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.endif # GST_BUZZTARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-buzztard
