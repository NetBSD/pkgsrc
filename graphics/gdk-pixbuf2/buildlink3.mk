# $NetBSD: buildlink3.mk,v 1.10 2019/07/21 20:33:02 wiz Exp $

BUILDLINK_TREE+=	gdk-pixbuf2

.if !defined(GDK_PIXBUF2_BUILDLINK3_MK)
GDK_PIXBUF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.22.0
BUILDLINK_ABI_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.38.1
BUILDLINK_PKGSRCDIR.gdk-pixbuf2?=	../../graphics/gdk-pixbuf2

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# GDK_PIXBUF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdk-pixbuf2
