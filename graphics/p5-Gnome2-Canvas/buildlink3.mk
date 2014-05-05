# $NetBSD: buildlink3.mk,v 1.21 2014/05/05 00:47:59 ryoon Exp $

BUILDLINK_TREE+=	p5-Gnome2-Canvas

.if !defined(P5_GNOME2_CANVAS_BUILDLINK3_MK)
P5_GNOME2_CANVAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-Gnome2-Canvas+=	p5-Gnome2-Canvas>=1.002
BUILDLINK_ABI_DEPENDS.p5-Gnome2-Canvas+=		p5-Gnome2-Canvas>=1.002nb22
BUILDLINK_PKGSRCDIR.p5-Gnome2-Canvas?=		../../graphics/p5-Gnome2-Canvas

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/p5-gtk2/buildlink3.mk"
.endif # P5_GNOME2_CANVAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-Gnome2-Canvas
