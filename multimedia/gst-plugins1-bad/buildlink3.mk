# $NetBSD: buildlink3.mk,v 1.5 2021/11/15 22:53:58 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-bad

.if !defined(GST_PLUGINS1_BAD_BUILDLINK3_MK)
GST_PLUGINS1_BAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-bad+=	gst-plugins1-bad>=1.18.4
BUILDLINK_ABI_DEPENDS.gst-plugins1-bad?=		gst-plugins1-bad>=1.18.5
BUILDLINK_PKGSRCDIR.gst-plugins1-bad?=		../../multimedia/gst-plugins1-bad

.include "../../multimedia/gstreamer1/buildlink3.mk"
.endif # GST_PLUGINS1_BAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-bad
