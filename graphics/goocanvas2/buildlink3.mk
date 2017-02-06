# $NetBSD: buildlink3.mk,v 1.7 2017/02/06 13:54:44 wiz Exp $
#

BUILDLINK_TREE+=	goocanvas2

.if !defined(GOOCANVAS2_BUILDLINK3_MK)
GOOCANVAS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.goocanvas2+=	goocanvas2>=2.0
BUILDLINK_ABI_DEPENDS.goocanvas2?=	goocanvas2>=2.0.1nb6
BUILDLINK_PKGSRCDIR.goocanvas2?=	../../graphics/goocanvas2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # GOOCANVAS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-goocanvas2
