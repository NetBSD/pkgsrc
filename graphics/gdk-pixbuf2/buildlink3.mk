# $NetBSD: buildlink3.mk,v 1.13 2021/12/08 16:02:09 adam Exp $

BUILDLINK_TREE+=	gdk-pixbuf2

.if !defined(GDK_PIXBUF2_BUILDLINK3_MK)
GDK_PIXBUF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.22.0
BUILDLINK_ABI_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.42.6
BUILDLINK_PKGSRCDIR.gdk-pixbuf2?=	../../graphics/gdk-pixbuf2

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# GDK_PIXBUF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdk-pixbuf2
