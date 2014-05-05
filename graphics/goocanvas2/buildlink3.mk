# $NetBSD: buildlink3.mk,v 1.4 2014/05/05 00:47:57 ryoon Exp $
#

BUILDLINK_TREE+=	goocanvas2

.if !defined(GOOCANVAS2_BUILDLINK3_MK)
GOOCANVAS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.goocanvas2+=	goocanvas2>=2.0
BUILDLINK_ABI_DEPENDS.goocanvas2?=	goocanvas2>=2.0.1nb3
BUILDLINK_PKGSRCDIR.goocanvas2?=	../../graphics/goocanvas2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # GOOCANVAS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-goocanvas2
