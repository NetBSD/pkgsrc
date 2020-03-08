# $NetBSD: buildlink3.mk,v 1.3 2020/03/08 16:47:58 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-bad

.if !defined(GST_PLUGINS1_BAD_BUILDLINK3_MK)
GST_PLUGINS1_BAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-bad+=	gst-plugins1-bad>=1.0.3
BUILDLINK_ABI_DEPENDS.gst-plugins1-bad+=	gst-plugins1-bad>=1.16.2nb2
BUILDLINK_PKGSRCDIR.gst-plugins1-bad?=		../../multimedia/gst-plugins1-bad

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif # GST_PLUGINS1_BAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-bad
