# $NetBSD: buildlink3.mk,v 1.20 2026/04/26 20:02:40 vins Exp $

BUILDLINK_TREE+=	colord-gtk

.if !defined(COLORD_GTK_BUILDLINK3_MK)
COLORD_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord-gtk+=	colord-gtk>=0.3.1
BUILDLINK_ABI_DEPENDS.colord-gtk?=	colord-gtk>=0.3.1nb1
BUILDLINK_PKGSRCDIR.colord-gtk?=	../../graphics/colord-gtk

pkgbase :=      colord-gtk
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.colord-gtk:Mgtk3}
.  include "../../x11/gtk3/buildlink3.mk"
.elif  ${PKG_BUILD_OPTIONS.colord-gtk:Mgtk4}
.  include "../../x11/gtk4/buildlink3.mk"
.endif

.endif	# COLORD_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-colord-gtk
