# $NetBSD: buildlink3.mk,v 1.33 2019/07/21 22:24:05 wiz Exp $
#

BUILDLINK_TREE+=	goocanvas

.if !defined(GOOCANVAS_BUILDLINK3_MK)
GOOCANVAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.goocanvas+=	goocanvas>=0.12
BUILDLINK_ABI_DEPENDS.goocanvas+=	goocanvas>=1.0.0nb25
BUILDLINK_PKGSRCDIR.goocanvas?=		../../graphics/goocanvas

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GOOCANVAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-goocanvas
