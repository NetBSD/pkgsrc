# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/10/07 23:11:02 wulf Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNURADIO_WXGUI_BUILDLINK3_MK:=	${GNURADIO_WXGUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnuradio-wxgui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnuradio-wxgui}
BUILDLINK_PACKAGES+=	gnuradio-wxgui

.if !empty(GNURADIO_WXGUI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnuradio-wxgui+=	gnuradio-wxgui>=0.3
BUILDLINK_PKGSRCDIR.gnuradio-wxgui?=	../../ham/gnuradio-wxgui
.endif	# GNURADIO_WXGUI_BUILDLINK3_MK

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
