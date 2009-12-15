# $NetBSD: buildlink3.mk,v 1.12 2009/12/15 21:40:00 joerg Exp $

BUILDLINK_TREE+=	guile-gtk

.if !defined(GUILE_GTK_BUILDLINK3_MK)
GUILE_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile-gtk+=	guile-gtk>=0.4
BUILDLINK_ABI_DEPENDS.guile-gtk?=	guile-gtk>=0.60nb3
BUILDLINK_PKGSRCDIR.guile-gtk?=	../../devel/guile-gtk

.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.endif # GUILE_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile-gtk
