# $NetBSD: buildlink3.mk,v 1.5 2012/03/03 00:11:55 wiz Exp $

BUILDLINK_TREE+=	gst-buzztard

.if !defined(GST_BUZZTARD_BUILDLINK3_MK)
GST_BUZZTARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-buzztard+=	gst-buzztard>=0.5.0
BUILDLINK_ABI_DEPENDS.gst-buzztard?=	gst-buzztard>=0.5.0nb4
BUILDLINK_PKGSRCDIR.gst-buzztard?=	../../audio/gst-buzztard

.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.endif # GST_BUZZTARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-buzztard
