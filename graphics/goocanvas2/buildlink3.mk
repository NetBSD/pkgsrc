# $NetBSD: buildlink3.mk,v 1.36 2026/06/11 07:17:06 wiz Exp $
#

BUILDLINK_TREE+=	goocanvas2

.if !defined(GOOCANVAS2_BUILDLINK3_MK)
GOOCANVAS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.goocanvas2+=	goocanvas2>=2.0
BUILDLINK_ABI_DEPENDS.goocanvas2?=	goocanvas2>=2.0.4nb22
BUILDLINK_PKGSRCDIR.goocanvas2?=	../../graphics/goocanvas2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # GOOCANVAS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-goocanvas2
