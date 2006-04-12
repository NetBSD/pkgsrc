# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:19 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNURADIO_WXGUI_BUILDLINK3_MK:=	${GNURADIO_WXGUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnuradio-wxgui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnuradio-wxgui}
BUILDLINK_PACKAGES+=	gnuradio-wxgui

.if !empty(GNURADIO_WXGUI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnuradio-wxgui+=	gnuradio-wxgui>=0.3
BUILDLINK_ABI_DEPENDS.gnuradio-wxgui?=	gnuradio-wxgui>=0.4nb2
BUILDLINK_PKGSRCDIR.gnuradio-wxgui?=	../../ham/gnuradio-wxgui
.endif	# GNURADIO_WXGUI_BUILDLINK3_MK

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
