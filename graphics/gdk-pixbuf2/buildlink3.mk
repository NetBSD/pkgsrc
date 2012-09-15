# $NetBSD: buildlink3.mk,v 1.7 2012/09/15 10:04:51 obache Exp $

BUILDLINK_TREE+=	gdk-pixbuf2

.if !defined(GDK_PIXBUF2_BUILDLINK3_MK)
GDK_PIXBUF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.22.0
BUILDLINK_ABI_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.26.3nb1
BUILDLINK_PKGSRCDIR.gdk-pixbuf2?=	../../graphics/gdk-pixbuf2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# GDK_PIXBUF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdk-pixbuf2
