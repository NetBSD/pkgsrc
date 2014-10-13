# $NetBSD: buildlink3.mk,v 1.45 2014/10/13 12:51:10 mef Exp $

BUILDLINK_TREE+=	gnuradio-wxgui

.if !defined(GNURADIO_WXGUI_BUILDLINK3_MK)
GNURADIO_WXGUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-wxgui+=	gnuradio-wxgui>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-wxgui+=	gnuradio-wxgui>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-wxgui?=	../../ham/gnuradio-wxgui
.endif # GNURADIO_WXGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-wxgui
