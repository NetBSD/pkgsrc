# $NetBSD: buildlink3.mk,v 1.3 2009/05/20 00:58:13 wiz Exp $

BUILDLINK_TREE+=	guile16-gtk

.if !defined(GUILE16_GTK_BUILDLINK3_MK)
GUILE16_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile16-gtk+=	guile16-gtk>=0.5
BUILDLINK_ABI_DEPENDS.guile16-gtk?=	guile16-gtk>=0.5nb1
BUILDLINK_PKGSRCDIR.guile16-gtk?=	../../devel/guile16-gtk

.include "../../lang/guile16/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.endif # GUILE16_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile16-gtk
